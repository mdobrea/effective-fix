/*
 * fix_error.hpp
 *
 *  Created on: 22.09.2014
 *      Author: Marius
 */

#ifndef FIX_ERROR_HPP_
#define FIX_ERROR_HPP_

#include <string>
#include <system_error>

namespace fix
{

enum class errcode
{
	empty_range=1,
	end_of_stream,
	invalid_iterator_state,
	out_of_range,
	missing_tag,
	invalid_argument
};

class error_category : public std::error_category
{
public:
	const char* name() const noexcept override { return "fix"; }
	std::string message(int ec) const override;
};

const error_category& get_error_category() noexcept;

struct fix_error : public std::system_error
{
	fix_error(errcode errc, const std::string& what_argc) : std::system_error{errc, what_argc} {}
};


}

#endif /* FIX_ERROR_HPP_ */
