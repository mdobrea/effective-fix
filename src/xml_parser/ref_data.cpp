/*
 * ref_data.cpp
 *
 *  Created on: 27.11.2014
 *      Author: Marius
 */

#include<fixp/ref_data.hpp>

namespace fixp
{

// TODO - move to common.hpp
const std::string TOKEN_XMLATTR { "<xmlattr>" };
const std::string TOKEN_FIXPTYPE { "fixptype" };
const std::string TOKEN_APPTYPE { "apptype" };
const std::string TOKEN_ALIAS { "alias" };

void ref_data::load_user_types(const ref_data::tree_type& types)
{
	for(const boost::property_tree::ptree::value_type& vt : types)
	{
		const tree_type& info = vt.second.get_child(TOKEN_XMLATTR);
		const tree_type& fixpType = info.get_child(TOKEN_FIXPTYPE);

		optional_tree alias =  info.get_child_optional(TOKEN_ALIAS);
		optional_tree appType;

		if(alias)
			appType = info.get_child_optional(TOKEN_APPTYPE);
		else
			appType = info.get_child("apptype");

		AggregatedTypes::const_iterator fixpTypePos = fixpTypes.insert(fixpType.data()).first;
		AggregatedTypes::const_iterator aliasPos = aliases.end();
		if(alias)
		{
			aliasPos = aliases.insert(alias->data()).first;
		}

		AggregatedTypes::const_iterator appTypePos = appTypes.end();
		if(appType)
		{
			appTypePos = appTypes.insert(appType->data()).first;
		}
	}
}
}

