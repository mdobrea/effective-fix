/*
 * traits.hpp
 *
 *  Created on: 09.11.2014
 *      Author: Marius
 */

#ifndef FIXP_TRAITS_HPP_
#define FIXP_TRAITS_HPP_

namespace fixp
{

class traits
{
public:
	using tag_type = int;
	using amt_type = double;
	using boolean_type=bool;
	using char_type = char;
	using currency_type=std::string;
	using data_type = std::string;
	using exchange_type = std::string;
	using float_type = double;
	using int_type = int;
	using length_type = size_t;
	using localmktdate_type = traits::localmktdate_type;
	using multiplecharvalue_type = traits::multiplecharvalue_type;
	using multiplestringvalue_type = traits::multiplestringvalue_type;
	using percentage_type = double;
	using price_type = double;
	using priceoffset_type = traits::priceoffset_type;
	using qty_type = traits::qty_type;
	using string_type = std::string;
	using utctimestamp_type = traits::utctimestamp_type;

};

}

#endif /* FIXP_TRAITS_HPP_ */
