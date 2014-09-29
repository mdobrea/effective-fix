/*
 * conversion.hpp
 *
 *  Created on: 22.09.2014
 *      Author: Marius
 */

#ifndef FIX_CONVERSION_HPP_
#define FIX_CONVERSION_HPP_

#include <stdexcept>
#include <fix/parse_error.hpp>

namespace fix
{

template <typename CharType, typename IntegralType>
IntegralType char2integral(CharType ch)
{
	switch(ch)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default:
	{
		std::string arg { "char2integral: not an integral; ch=" };
		arg += ch;
		throw parse_error { errcode::invalid_argument, arg };
	}
	}
}

// todo enable_if forward iterator and IntegralType
template <typename InputIterator, typename IntegralType>
IntegralType convert(InputIterator& begin, InputIterator end, typename std::iterator_traits<Iterator>::value_type tag_separator = '=')
{
	if(begin == end)
		throw parse_error { errcode::empty_range };

	if(*begin == tag_separator)
		throw parse_error { errcode::missing_tag };

	IntegralType tag {};

	for(; begin != end; ++begin)
	{
		int ch = *begin;
		if(ch == tag_separator)
		{
			++begin;
			return;
		}

		IntegralType val = char2integral<IntegralType>(*begin);

		if(tag  > (std::numeric_limits<IntegralType>::max() - val) / 10)
			throw parse_error { errcode::out_of_range };

		tag = tag*10 + val;
	}

	throw parse_error { errcode::end_of_stream };
}

constexpr bool is_type_data_tag(tag t)
{
	switch(t)
	{
	case tag::signature:
	case tag::secure_data:
	case tag::raw_data:
	case tag::xml_data:
	case tag::encoded_issuer:
		return true;
	};
	return false;
}


}


#endif /* FIX_CONVERSION_HPP_ */
