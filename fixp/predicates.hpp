/*
 * predicates.hpp
 *
 *  Created on: Dec 23, 2014
 *      Author: cb2dous
 */

#ifndef FIXP_PREDICATES_HPP_
#define FIXP_PREDICATES_HPP_

namespace fixp
{

// use when the message contain no data tag
struct no_data_tag
{
	template<typename Tag>
	bool operator()(Tag tag) const
	{
		return false;
	}
};

}

#endif /* IT_FIXP_PREDICATES_HPP_ */
