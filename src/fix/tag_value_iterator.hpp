/*
 * tag_value_iterator.hpp
 *
 *  Created on: 23.09.2014
 *      Author: Marius
 */

#ifndef TAG_VALUE_ITERATOR_HPP_
#define TAG_VALUE_ITERATOR_HPP_

#include <fix/tag_value.hpp>

namespace fix
{

template<typename FixTraits, typename Iterator>
class tag_value_iterator : 	public std::iterator<std::forward_iterator_tag,	tag_value<FixTraits, Iterator>>

{
public:
	using type=tag_value_iterator<FixTraits, Iterator>;

	tag_value_iterator(
		Iterator begin,
		Iterator end,
		typename std::iterator_traits<Iterator>::value_type separator = 1)
		: begin{begin}, end{end}, separator{separator}, valid {begin != end}
	{
		if(valid)
			increment();
	}

	tag_value_iterator() : begin{}, end{}, separator{1}, valid(false) {}

	const type& operator++()
	{
		increment();
		return *this;
	}

	bool operator==(const type& a) const
	{
		return (a.valid && valid) ? ( (a.begin==begin) && (a.end == end) ) : (a.valid==valid);
	}

	bool operator!=(const type& a) const
	{
		return !(*this == a);
	}

	value_type& operator*() { return *this; };
	const value_type& operator*() const { return *this; };

private:
	void increment()
	{
		if(!valid)
			throw errcode { errcode::invalid_iterator_state };
		if(begin == end)
		{
			valid = false;
			return;
		}
		this->tag = convert<typename FixTraits::tagnum_type>(begin, end);
		this->first = begin;
		this->second = std::find(begin, end, separator);
		if(this->second == end)
		{
			throw parse_error { errcode::end_of_stream };
		}
		begin = this->second;
		++begin;
	}

	Iterator begin;
	Iterator end;
	typename std::iterator_traits<Iterator>::value_type separator;
	bool valid;
	value_type value;
};


template<typename FixTraits, typename Iterator, typename Function>
Function for_each(Iterator first, Iterator last, Function function, typename std::iterator_traits<Iterator>::value_type separator)
{
	std::for_each(tag_value_iterator<FixTraits, Iterator>{first, last, separator},
		tag_value_iterator<FixTraits, Iterator>{},
		function);
}

template<typename FixTraits, typename Iterator>
void dumpMessage(Iterator first, Iterator last, typename std::iterator_traits<Iterator>::value_type separator, typename std::iterator_traits<Iterator>::value_type recordSeparator)
{
	for_each(first, last, [](const tag_value<FixTraits, Iterator>& cv) { std::cout << cv << recordSeparator; }, separator);
}


}

#endif /* TAG_VALUE_ITERATOR_HPP_ */
