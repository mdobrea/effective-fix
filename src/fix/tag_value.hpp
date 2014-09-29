/*
 * tag_value.hpp
 *
 *  Created on: 22.09.2014
 *      Author: Marius
 */

#ifndef TAG_VALUE_HPP_
#define TAG_VALUE_HPP_

#include <ostream>
#include <utility>

namespace fix
{

template<typename TraitsType, typename Iterator>
struct tag_value : public std::pair<Iterator, Iterator>
{
	TraitsType::tag_enum_type tag {};
};

template<typename TraitsType, typename Iterator>
std::ostream& operator<<(std::ostream& os, const tag_value<TraitsType, Iterator>& tv)
{
	os << '{' << tv.tag << "," << std::string { tv.first, tv.second } << '}';
	return os;
}

}



#endif /* TAG_VALUE_HPP_ */
