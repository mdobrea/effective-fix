/*
 * iterator.hpp
 *
 *  Created on: 17.12.2014
 *      Author: Marius
 */

#ifndef FIXP_ITERATOR_HPP_
#define FIXP_ITERATOR_HPP_

#include<boost/token_iterator.hpp>

namespace fixp {

template<typename TagType, typename Iterator>
class iterator_value
{
	boost::optional<TagType> tag;
	Iterator first;
	Iterator last;
};

template<typename TagType, typename Iterator, typename IsBinaryTagPredicate>
class field_tokenizer
{
public:
	using char_type=typename std::iterator_traits<Iterator>::value_type;
	field_tokenizer(
		IsBinaryTagPredicate predicate,
		char_type field_separator = 1,
		char_type tag_separator = '=')
		: predicate{predicate},
		  field_separator{field_separator},
		  tag_separator{tag_separator}
		{}

		// TODO - implement operator()
private:
	IsBinaryTagPredicate predicate {};
	char_type field_separator {};
	char_type tag_separator {};
};

template <typename TagType, typename Iterator, typename IsBinaryTagPredicate>
boost::token_iterator_generator<
	field_tokenizer<TagType, Iterator, IsBinaryTagPredicate>,
	Iterator,
	iterator_value<TagType, Iterator>
	>
make_iterator(
	Iterator begin, Iterator end,
	IsBinaryTagPredicate predicate,
	typename std::iterator_traits<Iterator>::value_type field_separator = 1,
	typename std::iterator_traits<Iterator>::value_type tag_separator = '=')
{
	return boost::make_token_iterator(
		begin, end,
		field_tokenizer<TagType, Iterator,
			IsBinaryTagPredicate>{predicate, field_separator, tag_separator});
}

} /* namespace fixp */

#endif /* IT_FIXP_FIXP_ITERATOR_HPP_ */
