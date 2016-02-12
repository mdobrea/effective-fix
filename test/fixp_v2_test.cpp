/*
 * fixp_v2_test.cpp
 *
 *  Created on: 12.02.2016
 *      Author: Marius
 */

#include <fixp/fixp_v2.hpp>

#define BOOST_TEST_MODULE FIXP_V2
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(ComponentTest)
{
	using namespace fixp;
	Instrument instrument;
	instrument.set<Symbol>("DBK");
	instrument.set<SecurityID>("DE0005140008");
	instrument.set<SecurityIDSource>(SecurityIDSourceEnum::IsinNumber);

	const Symbol::value_type& symbol = instrument.get<Symbol>();
	const SecurityID::value_type& securityID = instrument.get<SecurityID>();
	const SecurityIDSource::value_type& securityIDSource = instrument.get<SecurityIDSource>();

	boost::optional<const Symbol::value_type&> symbolOpt = instrument.getCOptional<Symbol>();
	boost::optional<const SecurityID::value_type&> securityIDOpt = instrument.getCOptional<SecurityID>();
	boost::optional<const SecurityIDSource::value_type&> securityIDSourceOpt = instrument.getCOptional<SecurityIDSource>();

	instrument.get<Symbol>() = "CBK";
	instrument.get<SecurityID>() = "CBK100";
	instrument.get<SecurityIDSource>() = SecurityIDSourceEnum::Wertpapier;

	*instrument.getOptional<Symbol>() = "DBK";
	*instrument.getOptional<SecurityID>() = "DE0005140008";
	*instrument.getOptional<SecurityIDSource>() = SecurityIDSourceEnum::IsinNumber;
}
