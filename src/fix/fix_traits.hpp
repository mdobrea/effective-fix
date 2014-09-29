/*
 * value_traits.hpp
 *
 *  Created on: 25.09.2014
 *      Author: Marius
 */

#ifndef FIX_TRAITS_HPP_
#define FIX_TRAITS_HPP_

#include<boost/variant.hpp>

namespace fix
{

namespace detail
{
using string_value_type=std::string;
}

template <
	typename int_type_=int,
	typename length_type_=unsigned,
	typename tagnum_type_=unsigned,
	typename seqnum_type_=unsigned,
	typename numingroup_type_=unsigned,
	typename dayofmmonth_type_=unsigned,
	typename float_type_=double,
	typename qty_type_=double,
	typename price_type_=double,
	typename priceoffset_type_=double,
	typename amt_type_=double,
	typename percentage_type_=double,
	typename char_type_=char,
	typename boolean_type_=bool,
	typename string_type_=detail::string_value_type,
	typename multiplecharvalue_type_=detail::string_value_type,
	typename country_type_=detail::string_value_type,
	typename currency_type_=detail::string_value_type,
	typename exchange_type_=detail::string_value_type,
	typename month_year_type_=detail::string_value_type,
	typename utctimestamp_type_=detail::string_value_type,
	typename utctimeonly_type_=detail::string_value_type,
	typename utcdateonly_type_=detail::string_value_type,
	typename localmktdate_type_=detail::string_value_type,
	typename tzttimeonly_type_=detail::string_value_type,
	typename tztimestamp_type_=detail::string_value_type,
	typename data_type_=detail::string_value_type,
	typename pattern_type_=detail::string_value_type,
	typename tenor_type_=detail::string_value_type,
	typename xmldata_type_=detail::string_value_type,
	typename language_type_=detail::string_value_type,
	typename localmkttime_type_=detail::string_value_type,
	typename xid_type_=detail::string_value_type,
	typename xidref_type_=detail::string_value_type,
	typename variant_type_=boost::variant<int,unsigned,double,detail::string_value_type,char,bool>,
	typename value_type_=variant_type_
>
struct fix_traits
{
	// todo - assert that int types are integral types, etc
	//

	using int_type=int_type_;
	using length_type=length_type_;
	using tagnum_type=tagnum_type_;
	using seqnum_type=seqnum_type_;
	using numingroup_type=numingroup_type_;
	using dayofmmonth_type=dayofmmonth_type_;
	using float_type=float_type_;
	using qty_type=qty_type_;
	using price_type=price_type_;
	using priceoffset_type=priceoffset_type_;
	using amt_type=amt_type_;
	using percentage_type=percentage_type_;
	using char_type=char_type_;
	using boolean_type=boolean_type_;
	using string_type=string_type_;
	using multiplecharvalue_type=multiplecharvalue_type_;
	using country_type=country_type_;
	using currency_type=currency_type_;
	using exchange_type=exchange_type_;
	using month_year_type=month_year_type_;
	using utctimestamp_type=utctimestamp_type_;
	using utctimeonly_type=utctimeonly_type_;
	using utcdateonly_type=utcdateonly_type_;
	using localmktdate_type=localmktdate_type_;
	using tzttimeonly_type=tzttimeonly_type_;
	using tztimestamp_type=tztimestamp_type_;
	using data_type=data_type_;
	using pattern_type=pattern_type_;
	using tenor_type=tenor_type_;
	using xmldata_type=xmldata_type_;
	using language_type=language_type_;
	using localmkttime_type=localmkttime_type_;
	using xid_type=xid_type_;
	using xidref_type=xidref_type_;

	using variant_type=variant_type_;
	using value_type=value_type_;
};
}


#endif /* FIX_TRAITS_HPP_ */
