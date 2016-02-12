/*
 * fixp_v2.hpp
 *
 *  Created on: 12.02.2016
 *      Author: Marius
 */

#ifndef IT_FIXP_FIXP_V2_HPP_
#define IT_FIXP_FIXP_V2_HPP_

#include <boost/container/string.hpp>
#include <boost/optional.hpp>
#include <type_traits>

namespace fixp
{

// tags
struct Symbol
{
	using value_type=boost::container::string;
};

struct SecurityID
{
	using value_type=boost::container::string;
};

enum class SecurityIDSourceEnum : char { IsinNumber = '4', Wertpapier='B' };

struct SecurityIDSource
{
	using value_type=SecurityIDSourceEnum;
};

template<typename ... Tags>
struct Component
{
	template<typename Tag>
	void set(const typename Tag::value_type& value)
	{
	}

	template<typename Tag>
	const typename Tag::value_type& get() const
	{
	}

	template<typename Tag>
	typename Tag::value_type& get()
	{
	}

	template<typename Tag>
	boost::optional<const typename Tag::value_type&> getOptional() const
	{
		return boost::none;
	}

	template<typename Tag>
	boost::optional<const typename Tag::value_type&> getCOptional() const
	{
		return boost::none;
	}

	template<typename Tag>
	boost::optional<typename Tag::value_type&> getOptional()
	{
		return boost::none;
	}
};

using Instrument=fixp::Component<Symbol, SecurityID, SecurityIDSource>;

}

#endif /* IT_FIXP_FIXP_V2_HPP_ */
