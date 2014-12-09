/*
 * data_dictionary_test.cpp
 *
 *  Created on: 09.12.2014
 *      Author: Marius
 */

#include <fixp/data_dictionary.hpp>
#include <type_traits>
#include <iostream>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(basic_asserts)
{
	static_assert(std::is_default_constructible<fixp::data_dictionary>::value,
		"data_dictionary not default constructible");
	static_assert(std::is_copy_constructible<fixp::data_dictionary>::value,
		"data_dictionary not copy constructible");
	static_assert(std::is_copy_assignable<fixp::data_dictionary>::value,
		"data_dictionary not copy assignable");
	static_assert(std::is_move_constructible<fixp::data_dictionary>::value,
		"data_dictionary not move constructible");
	static_assert(std::is_move_assignable<fixp::data_dictionary>::value,
		"data_dictionary not move assignable");
}

BOOST_AUTO_TEST_CASE(test_types)
{
	fixp::data_dictionary d;
	d.add_type("price", nullptr, nullptr);
	d.add_type("quantity", nullptr, nullptr);

	BOOST_CHECK_EQUAL(d.get_types().size(), 2u);
	BOOST_CHECK(d.contains_type("quantity"));
	BOOST_CHECK(d.contains_type("price"));
	BOOST_CHECK(!d.contains_type("unknown"));

}

