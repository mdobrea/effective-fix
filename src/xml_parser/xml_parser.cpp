/*
 * xml_parser.cpp
 *
 *  Created on: 05.11.2014
 *      Author: Marius
 */

#include "header_file_scope.hpp"
#include <fixp/xml_parser.hpp>

// #include <boost/property_tree/info_parser.hpp>
// #include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

namespace fixp
{
void xml_parser::load_specs(const xml_parser::tree_type& fixTree, const xml_parser::tree_type& userTree)
{
	const boost::property_tree::ptree& fields = fixTree.get_child("fix").get_child("fields");
	load_fields(fields);
}

void xml_parser::load_fields(const xml_parser::tree_type& fields)
{
	for(const boost::property_tree::ptree::value_type& vt : fields)
	{
		const tree_type& info = vt.second.get_child("<xmlattr>");
		const tree_type& tag = info.get_child("number");
		const tree_type& name =  info.get_child("name");
		const tree_type& type = info.get_child("type");

		// TODO - use emplace
		field_attributes.insert(FieldAttributes::value_type
		{
			name.data(),
			FieldAttribute{tag.data(), *types.insert(type.data()).first}
		});
	}
}

void xml_parser::write_traits(std::ostream& out)
{
	header_file_scope scope {"tags", {"fixp/traits.hpp"}, {"fixp", "tags"}, out};
	out << "\tusing tag_type=traits::tag_type;\n\n";
	for(const FieldAttributes::value_type& vt : field_attributes)
	{
		out << "\tconstexpr tag_type " << vt.first << "=" << *vt.second.tag << ";\n";
	}
}

void xml_parser::write_tags(std::ostream& out)
{
	header_file_scope scope {"tags", {}, {"fixp"}, out};
	out << "class traits\n{\npublic:\n";
	for(const std::string& type : types)
	{
		out << "\tusing " << type << "=" << type << ";\n";
	}
}

void xml_parser::write_message(std::ostream& out, const xml_parser::tree_type& message)
{
	const tree_type& xmlattr = message.get_child("<xmlattr>");


	std::set<std::string> fields; // todo - use const references to std::string, use vector instead
	std::set<std::string> types;

	for(const tree_type::value_type& vt : message)
	{
		if(vt.first == "field")
		{
			const tree_type& field = vt.second.get_child("<xmlattr>");
			const tree_type& name = field.get_child("name");
			fields.insert(name.data()); // todo - use emplace, check if it already exists in the collection

			FieldAttributes::const_iterator it = field_attributes.find(name.data());
			if(field_attributes.end() != it)
				types.insert(*it->second.type);
		}
	}

	const std::string& name = xmlattr.get_child("name").data();
	header_file_scope scope {name, { "fixp/tags.hpp", "fixp/traits.hpp", }, {"fixp"}, out};

	std::string tmp;

	out << "\nclass " << xmlattr.get_child("name").data() <<
			" : public fixp::component\n"
			"{\n"
			"public:\n";


	// generate typedefs
	out << "\tusing Base = fixp::component;\n";
	out << "\tusing tag_type = traits::tag_type;\n";
	for(const std::string& type : types)
	{
		out << "\tusing " << type << "_type = traits::" << type << "_type;\n";
	}

	out << "\n\t// observers\n\n";

	for(const std::string& field : fields)
	{
		FieldAttributes::const_iterator it = field_attributes.find(field);
		out << "\t";
		if(field_attributes.end() == it)
			out << "UnknownType";
		else
		{
			tmp = *it->second.type;
			tmp += "_type";
			out << tmp;
		}

		out << " get" << field << "() { return Base::getField(tags::" << field << "); }\n";
	}


	out << "\n\t// modifiers \n\n";

	for(const std::string& field : fields)
	{
		FieldAttributes::const_iterator it = field_attributes.find(field);
		out << "\t";
		if(field_attributes.end() == it)
			out << "UnknownType";
		else
		{
			tmp = *it->second.type;
			tmp += "_type";
		}

		out << "void set" << field <<
			"("<< tmp << " " << field << ") { Base::setField(tags::" << field << ", " << field << "); }\n";
	}

	out << "};\n";
}

}


