/*
 * iterator_test.cpp
 *
 *  Created on: Dec 18, 2014
 *      Author: cb2dous
 */

#include <fixp/iterator.hpp>
#include <fixp/predicates.hpp>

#define BOOST_TEST_MODULE COMPONENT
#include <boost/test/unit_test.hpp>

using TagType=unsigned;

BOOST_AUTO_TEST_CASE( fieldTokenizerTest )
{
	std::string msg;

	fixp::token<unsigned, std::string::iterator> t1;
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(!(t1.first != t1.second));

	fixp::field_tokenizer<unsigned, std::string::iterator, fixp::no_data_tag, '|', '='> f1;
	fixp::field_tokenizer<unsigned, std::string::iterator, fixp::no_data_tag> f2 { fixp::no_data_tag{} };
	fixp::field_tokenizer<unsigned, std::string::iterator, fixp::no_data_tag> f3;

	std::string::iterator first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == false);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);
	BOOST_CHECK(t1.first == t1.second);

	msg = "|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "="; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "=|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "abc"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "abc="; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "abc|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "abc=|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == msg.end());
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "-1234="; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "1234="; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.value() == 1234);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "=abc"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(t1.first == t1.second);
	BOOST_CHECK(first == t1.second);
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "=abc|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.is_initialized() == false);
	BOOST_CHECK(std::distance(t1.first, t1.second) == 3 && std::equal(t1.first, t1.second, msg.begin()+1));
	BOOST_CHECK(first == msg.end());
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "1234=abc|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.value() == 1234);
	BOOST_CHECK(std::distance(t1.first, t1.second) == 3 && std::equal(t1.first, t1.second, msg.begin()+5));
	BOOST_CHECK(first == msg.end());
	BOOST_CHECK(f1(first, msg.end(), t1) == false);

	msg = "12=ab|34=cd|"; first = msg.begin();
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.value() == 12);
	BOOST_CHECK(std::distance(t1.first, t1.second) == 2 && std::equal(t1.first, t1.second, msg.begin()+3));
	BOOST_CHECK(f1(first, msg.end(), t1) == true);
	BOOST_CHECK(t1.tag.value() == 34);
	BOOST_CHECK(std::distance(t1.first, t1.second) == 2 && std::equal(t1.first, t1.second, msg.begin()+9));
	BOOST_CHECK(f1(first, msg.end(), t1) == false);
}

BOOST_AUTO_TEST_CASE( iteratorTest )
{
	std::string msg;
	fixp::make_iterator<unsigned, std::string::const_iterator, fixp::no_data_tag, '|', '='>(msg.begin(), msg.end(), fixp::no_data_tag{});

//	msg="8=FIX.4.1|9=112|35=0|49=BRKR|56=INVMGR|34=235|52=19980604-07:58:28|112=19980604-07:58:28|10=157|";
//	first = msg.begin();
//	f1.reset();
	//fixp::field_tokenizer<unsigned, std::string::iterator, fixp::no_data_tag, '|', '='> ft;
	//auto x = boost::make_token_iterator< fixp::token<unsigned, std::string::iterator> >(msg.begin(), msg.end(), ft);
	//std::cout << x;

}
