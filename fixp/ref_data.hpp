/*
 * ref_data.hpp
 *
 *  Created on: 27.11.2014
 *      Author: Marius
 */

#ifndef FIXP_REF_DATA_HPP_
#define FIXP_REF_DATA_HPP_

#include <boost/container/flat_set.hpp>
#include <boost/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <string>

namespace fixp
{

class ref_data
{
public:


	using tree_type=boost::property_tree::ptree;
	using optional_tree=boost::optional<const tree_type&>;
	void load_user_types(const tree_type& types);

private:



	using AggregatedTypes=boost::container::flat_set<std::string>;


	AggregatedTypes fixpTypes, aliases, appTypes;


};
}

#endif /* FIXP_REF_DATA_HPP_ */
