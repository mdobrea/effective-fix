/*
 * fixp_error.hpp
 *
 *  Created on: 22.09.2014
 *      Author: Marius
 */

#ifndef FIXP_ERROR_HPP_
#define FIXP_ERROR_HPP_

#include <string>
#include <stdexcept>

namespace fixp
{

enum class error_code
{
	empty_range=1,
	end_of_stream,
	empty_type_alias,
	empty_type_name,
	empty_user_type_name,
	invalid_iterator_state,
	out_of_range,
	missing_tag,
	invalid_argument
};

struct fixp_error : public std::runtime_error
{
	fixp_error(error_code errc, const std::string& what = std::string{}) : std::runtime_error{message(errc, what)}, errc { errc } {}

	// TODO - implement it
	std::string message(error_code errc, const std::string& what) const {
		return std::string {};
	}
private:
	error_code errc;
};

}

#endif /* FIXP_ERROR_HPP_ */
