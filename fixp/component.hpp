/*
 * component.hpp
 *
 *  Created on: 30.10.2014
 *      Author: Marius
 */

#ifndef FIXP_COMPONENT_HPP_
#define FIXP_COMPONENT_HPP_

#include <fixp/traits.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/variant.hpp>
#include <string>

namespace fixp
{

class component : public boost::container::flat_map<traits::tag_type, boost::variant<char,int,double,std::gregorian::date,std::string,component>>
{
public:
	using tag_type = traits::tag_type;

	template<typename T>
	void putField(tag_type tag, T t)
	{

	}

	template<typename T>
	T& getField(tag_type tag)
	{

	}
};

#endif /* FIXP_COMPONENT_HPP_ */
