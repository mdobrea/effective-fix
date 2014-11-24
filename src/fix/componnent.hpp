/*
 * componnent.hpp
 *
 *  Created on: 07.10.2014
 *      Author: Marius
 */

#ifndef FIX_COMPONNENT_HPP_
#define FIX_COMPONNENT_HPP_

#include <boost/variant.hpp>
#include <vector>

namespace fix
{

// component implemented with an underlying vector
class componnent
{
public:
	using key_type=int;
	using mapped_type=boost::variant<int, componnent>;
	using value_type=std::pair<key_type,mapped_type>;
	using container_type=std::vector<value_type>;
	using iterator=container_type::iterator;
	using const_iterator=container_type::const_iterator;

	template<typename T>
	void put(key_type key, const T& value)
	{
		iterator iter = find(key);
		if(fields.end()==iter)
			fields.emplace_back(key, value);
		else
			iter->second = value;
	}

	template<typename T>
	const T* get(key_type key) const
	{
		const_iterator iter = find(key);
		if(fields.end()==iter)
			return nullptr;
		return boost::get<T>(&iter->second);
	}

private:

	template<typename T>
	std::pair<iterator, bool> emplace(key_type key, const T& value)
	{
		iterator iter = find(key);
		if(fields.end()==iter)
		{
			fields.emplace_back(key, value);
			return std::make_pair(fields.end() -1, true);
		}
		return std::make_pair(iter, false);
	}

	iterator find(key_type key)
	{

		return std::find_if(fields.begin(), fields.end(), [=](const value_type& vt) { return vt.first == key; });
	}

	const_iterator find(key_type key) const
	{
		return std::find_if(fields.begin(), fields.end(), [=](const value_type& vt) { return vt.first == key; });
	}


	container_type fields;
};

}



#endif /* FIX_COMPONNENT_HPP_ */
