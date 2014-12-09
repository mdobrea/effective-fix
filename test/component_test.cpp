#include <fixp/component.hpp>
#include <iostream>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_main)
{
	fixp::component instrument;
	instrument[55] = "FDAX";
	
	std::cout << "instrument[55]=" << boost::get<std::string>(instrument[55]) << '\n';
}

