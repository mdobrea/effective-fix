/*
 * tags.hpp
 *
 *  Created on: Sep 8, 2014
 *      Author: cb2dous
 */

#ifndef FIX_TAGS_
#define FIX_TAGS_

// TODO - generate based on the schema

namespace fix
{

enum class tag
{
	signature,
	secure_data,
	raw_data,
	xml_data,
	encoded_issuer
};

}

 #endif /* FIX_TAGS_ */