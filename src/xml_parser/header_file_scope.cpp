/*
 * header_file_scope.cpp
 *
 *  Created on: 10.11.2014
 *      Author: Marius
 */

#include "header_file_scope.hpp"
#include <boost/algorithm/string.hpp>

header_file_scope::header_file_scope(
	const std::string& filename,
	const std::vector<std::string>& inclusions,
	const std::vector<std::string>& namespaces,
	std::ostream& out)
	: namespaces{namespaces.size()}, out(out)
{
	std::string guard;
	std::string tmp;

	for(const std::string& namespace_ : namespaces)
	{
		tmp = namespace_;
		boost::algorithm::to_upper(tmp);
		guard += tmp;
		guard += '_';
	}

	tmp = filename;
	boost::algorithm::to_upper(tmp);
	guard += tmp;
	guard += "_HPP_";

	out << "#ifndef " << guard << "\n#define " << guard << "\n\n";

	for(const std::string& inclusion: inclusions)
	{
		out << "#include <" << inclusion << ">\n";
	}

	for(const std::string& namespace_: namespaces)
	{
		out << "namespace " << namespace_ << "\n{\n";
	}

}

header_file_scope::~header_file_scope()
{
	for(;namespaces; --namespaces)
	{
		out << "}\n";
	}
	out << "#endif\n";
}
