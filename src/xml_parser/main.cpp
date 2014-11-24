/*
 * main.cpp
 *
 *  Created on: 06.11.2014
 *      Author: Marius
 */

#include <fixp/xml_parser.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

int main(int argc, const char* argv[])
{
	namespace po = boost::program_options;

	std::string userFile;
	std::string fixFile;
	bool generateTags {};
	bool generateTraits {};
	{
		po::options_description desc("Allowed options");
		desc.add_options()
		    ("help", "produce help message")
		    ("fix-spec-file", po::value<std::string>(&fixFile)->required(), "FIX protocol spec file")
		    ("generate-tags", po::value<bool>(&generateTags)->implicit_value(true), "generate tags.hpp")
		    ("generate-traits", po::value<bool>(&generateTraits)->implicit_value(true), "generate basic_traits.hpp")
		    ("user-spec-file", po::value<std::string>(&userFile), "user spec file")
		;

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);

		if (vm.count("help")) {
		    std::cout << desc << "\n";
		    return 1;
		}

		po::notify(vm);
	}

	boost::property_tree::ptree fixTree;
	boost::property_tree::xml_parser::read_xml(fixFile, fixTree);

	boost::property_tree::ptree userTree;
	if(!userFile.empty())
	{
		boost::property_tree::xml_parser::read_xml(userFile, userTree);
	}

	fixp::xml_parser parser;
	parser.load_specs(fixTree, userTree);
	//boost::property_tree::info_parser::write_info(std::cout, fields);

	//std::set<std::string> types = parser.get_types();
	//std::copy(types.begin(), types.end(), std::ostream_iterator<std::string>{std::cout, ","});

	if(generateTags)
	{
		parser.write_tags(std::cout);
	}
	else if(generateTraits)
	{
		parser.write_traits(std::cout);
	}
	else
	{
		const boost::property_tree::ptree& messages = fixTree.get_child("fix").get_child("messages");
		for(const boost::property_tree::ptree::value_type& vt : messages)
		{
			if(vt.first == "message")
			{
				const boost::property_tree::ptree& xmlattr = vt.second.get_child("<xmlattr>");
				if(xmlattr.get_child("msgtype").data() == "8")
				{
					//boost::property_tree::info_parser::write_info(std::cout, vt.second);
					parser.write_message(std::cout, vt.second);
				}
			}
		}
	}
	return 0;
}



