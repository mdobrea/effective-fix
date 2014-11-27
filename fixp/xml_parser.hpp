/*
 * xml_parser.hpp
 *
 *  Created on: 06.11.2014
 *      Author: Marius
 */

#ifndef FIXP_XML_PARSER_HPP_
#define FIXP_XML_PARSER_HPP_

#include <fixp/ref_data.hpp>
#include <boost/property_tree/ptree.hpp>
#include <ostream>
#include <map>
#include <set>

namespace fixp
{



class xml_parser
{
public:
	using tree_type=boost::property_tree::ptree;
	void load_specs(const tree_type& fixTree, const tree_type& userTree);

	void write_traits(std::ostream& out);
	void write_tags(std::ostream& out);
	void write_message(std::ostream& out, const tree_type& message);

//	const std::set<std::string>& get_types() const { return types; }
private:
	struct FieldAttribute
	{
		FieldAttribute(const std::string& tag, const std::string& type)
		: tag{&tag}, type{&type} {}
		const std::string* tag;
		const std::string* type;
	};

	void load_fields(const tree_type& fields);

	// TODO - implement key of const std::string&
	using FieldAttributes=std::map<std::string, FieldAttribute>;
	FieldAttributes field_attributes;

	std::set<std::string> types; // TODO - remove
	ref_data data;
};

}

#endif /* FIXP_XML_PARSER_HPP_ */
