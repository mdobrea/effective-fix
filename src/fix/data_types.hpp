/*
 * data_types.hpp
 *
 *  Created on: 25.09.2014
 *      Author: Marius
 */

#ifndef FIX_DATA_TYPES_HPP_
#define FIX_DATA_TYPES_HPP_

namespace fix
{

enum class data_type
{
	int_,
	length,
	tagnum,
	seqnum,
	numingroup,
	dayofmmonth,
	float_,
	qty,
	price,
	priceoffset,
	amt,
	percentage,
	char_,
	boolean,
	string,
	multiplecharvalue,
	country,
	currency,
	exchange,
	month_year,
	utctimestamp,
	utctimeonly,
	utcdateonly,
	localmktdate,
	tzttimeonly,
	tztimestamp,
	data,
	pattern,
	tenor,
	xmldata,
	language,
	localmkttime,
	xid,
	xidref
};
}

#endif /* FIX_DATA_TYPES_HPP_ */
