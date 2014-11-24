/*
 * header_file_scope.hpp
 *
 *  Created on: 10.11.2014
 *      Author: Marius
 */

#ifndef HEADER_FILE_SCOPE_HPP_
#define HEADER_FILE_SCOPE_HPP_

#include <ostream>
#include <string>
#include <vector>

class header_file_scope {
public:
	header_file_scope(
		const std::string& filename,
		const std::vector<std::string>& inclusions,
		const std::vector<std::string>& namespaces,
		std::ostream& out);
	~header_file_scope();

private:
	size_t namespaces;
	std::ostream& out;
};

#endif /* HEADER_FILE_SCOPE_HPP_ */
