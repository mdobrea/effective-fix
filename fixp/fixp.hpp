/*
 * fixp.hpp
 *
 *  Created on: 03.01.2016
 *      Author: Marius
 */

#ifndef IT_FIXP_FIXP_HPP_
#define IT_FIXP_FIXP_HPP_

#include <boost/container/flat_map.hpp>
#include <array>
#include <typeinfo>
#include <typeindex>

namespace fixp
{

class security_id_source_isin_number
{
public:
	constexpr char value='4';
};

template <typename SecurityIDSource>
class security_id;


// has one invariant - a valid isin
class security_id<security_id_source_isin_number>
{
public:

private:
	std::array<char, 12> _isin;
};

// container of securityIDs
// it can not contain the same securityIDSource twice
class security_ids
{
public:
	using value_type=std::pair<std::type_index, boost::any>;

	template <typename SecurityIDSource>
	std::pair<const security_id<SecurityIDSource>&, bool> insert(const security_id<SecurityIDSource>& securityID)
	{
		std::pair<IDs::iterator, bool> ret =_ids.insert(value_type{std::type_index(typeid(security_id<SecurityIDSource>))});
		return std::pair{ret.first->second, ret.second};
	}
private:
	using IDs=boost::flat_map<std::type_index, boost::any>;
	IDs _ids;
};


};

#endif /* IT_FIXP_FIXP_HPP_ */
