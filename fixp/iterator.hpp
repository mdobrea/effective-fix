/*
 * iterator.hpp
 *
 *  Created on: 17.12.2014
 *      Author: Marius
 */

#ifndef FIXP_ITERATOR_HPP_
#define FIXP_ITERATOR_HPP_

#include <boost/convert.hpp>
#include <boost/convert/spirit.hpp>
#include <boost/optional.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/token_iterator.hpp>
#include <string>

namespace fixp {

template<typename Tag = unsigned, typename Iterator = std::string::iterator>
class token
{
public:
	boost::optional<Tag> tag;
	Iterator first;
	Iterator second;
};

template<
	typename Tag,
	typename Iterator,
	typename Predicate,
	typename std::iterator_traits<Iterator>::value_type FieldSeparator=1,
	typename std::iterator_traits<Iterator>::value_type TagSeparator='='
>
class field_tokenizer
{
public:
	explicit field_tokenizer() {}
	explicit field_tokenizer(Predicate predicate) : predicate(predicate) {}

	template<typename Token>
	bool operator()(Iterator& first, Iterator end, Token& token)
	{
		token = Token {};

		Iterator next = first;
		if(next == end)
		{
			return false;
		}

		for(;next != end && *next != FieldSeparator && *next != TagSeparator;++next)
			;

		if(next == end)
		{
			first = end;
			token.first = end;
			token.second= end;
			return true;
		}
		else if(*next == FieldSeparator)
		{
			first = ++next;
			token.first = end;
			token.second= end;
			return true;
		}
		else // *next == TagSeparator
		{
			token.tag = boost::convert<Tag>(boost::make_iterator_range(first, next), converter);
			first = ++next;
		}

		const bool isDataField = token.tag && predicate(token.tag.value());

		if(isDataField)
		{

		}
		else
		{
			for(;next != end && *next != FieldSeparator; ++next)
				;

			if(next == end)
			{
				first = end;
				token.first = end;
				token.second= end;
			}
			else
			{
				token.first = first;
				token.second= next;
				first = ++next;
			}
		}

		return true;
	}
	void reset() {}

private:
	Predicate predicate {};
	boost::cnv::spirit converter {};
};

template <
	typename Tag,
	typename Iterator,
	typename Predicate,
	typename std::iterator_traits<Iterator>::value_type FieldSeparator=1,
	typename std::iterator_traits<Iterator>::value_type TagSeparator='='
>
typename boost::token_iterator_generator<
	field_tokenizer<Tag, Iterator, Predicate, FieldSeparator, TagSeparator>,
	Iterator,
	token<Tag, Iterator>
>::type
make_iterator(Iterator begin, Iterator end, Predicate predicate)
{
	field_tokenizer<Tag, Iterator, Predicate, FieldSeparator, TagSeparator> ft{predicate};
	return boost::make_token_iterator< token<Tag, Iterator> >(begin, end, ft);
}

} /* namespace fixp */

#endif /* IT_FIXP_FIXP_ITERATOR_HPP_ */

