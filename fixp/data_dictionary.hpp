/*
 * data_dictionary.hpp
 *
 *  Created on: 08.12.2014
 *      Author: Marius
 */

#ifndef FIXP_DATA_DICTIONARY_HPP_
#define FIXP_DATA_DICTIONARY_HPP_

#include <fixp/fixp_error.hpp>
#include <set>

namespace fixp {

class data_dictionary
{
public:
	class type_info
	{
	public:
		type_info(
			const std::string& name,
			const std::string* alias,
			const std::string* user_type_name)
		: name(name), alias(alias), user_type_name(user_type_name)
		{
			if(name.empty())
				throw fixp_error{ error_code::empty_type_name };
			if(alias)
				set_alias(*alias);
			if(user_type_name)
				set_user_type_name(*user_type_name);
		}

		void set_alias(const std::string& alias_) {
			if(alias_.empty())
				throw fixp_error{ error_code::empty_type_alias };
			alias = &alias_;
		}

		void set_user_type_name(const std::string& user_type_name_) {
			if(user_type_name_.empty())
				throw fixp_error{ error_code::empty_user_type_name };
			user_type_name = &user_type_name_;
		}
		bool operator<(const type_info& other) const {
			return name < other.name;
		}

		const std::string& get_name() const { return name; };
		const std::string* get_alias() const { return alias; };
		const std::string* get_user_type_name() const { return user_type_name; };

	private:
		const std::string name;
		const std::string* alias {};
		const std::string* user_type_name {};
	};

	const type_info& add_type(
		const std::string& name,
		const std::string* alias,
		const std::string* user_type_name)
	{
		type_info& existing = const_cast<type_info&>(*types.insert(type_info { name, nullptr, nullptr }).first);
		if(alias)
			existing.set_alias(*aliases.insert(*alias).first);
		if(user_type_name)
			existing.set_user_type_name(*user_types.insert(*user_type_name).first);
		return existing;
	}

	const std::set<type_info>& get_types() const { return types; }

private:
	std::set<type_info> types;
	std::set<std::string> aliases;
	std::set<std::string> user_types;
};

} /* namespace fixp */

#endif /* FIXP_DATA_DICTIONARY_HPP_ */
