#include "../message_tokenizer.hpp"
#include "../tags.hpp"
#include <iostream>
#include <vector>

#include <regex>

void parse(const std::string& message, char separator)
{
	effective_fix::message_tokenizer tokens(message, separator);
	std::for_each(tokens.begin(), tokens.end(), [](const std::string& token){ std::cout << token << "\n"; });
}

enum class errcode
{
	empty_range,
	end_of_stream,
	invalid_iterator_state,
	numeric_overflow,
	missing_tag,
	not_a_number
};

struct parse_error
{
	parse_error(errcode errc) {}
};


template<typename InputIterator>
struct tag_value_iterator_value_type
{
	int tag {};
	InputIterator first {};
	InputIterator second {};
};

// todo - determine automatically SeparatorType from iterator traits
template<typename Iterator, typename SeparatorType>
class tag_value_iterator : public tag_value_iterator_value_type<Iterator>
{
public:
	tag_value_iterator(Iterator begin, Iterator end, SeparatorType separator = 1)
		: begin{begin}, end{end}, separator{separator}, valid {begin != end}
	{
		if(valid)
			increment();
	}

	tag_value_iterator() : begin{}, end{}, separator{1}, valid(false) {}

private:
	void increment()
	{
		if(!valid)
			throw errcode { errcode::invalid_iterator_state };
		if(begin == end)
			valid = false;
		parseTag();
		this->first = begin;
		this->second = std::find(begin, end, separator);
		if(this->second == end)
			throw parse_error { errcode::end_of_stream };
		begin = this->second;
		++begin;
	}

	void parseTag()
	{
		if(begin == end)
			throw parse_error { errcode::empty_range };

		if(*begin == '=')
			throw parse_error { errcode::missing_tag };

		int ch = *begin++;

		if(!std::isdigit(ch))
			throw parse_error { errcode::not_a_number };

		this->tag= ch - '0';	// TODO: may not be portable

		for(; begin != end; ++begin)
		{
			ch = *begin;
			if(ch == '=')
			{
				++begin;
				return;
			}

			if(!std::isdigit(ch))
				throw parse_error { errcode::not_a_number };

			if(this->tag  > (std::numeric_limits<int>::max() - (ch-'0')) / 10)
				throw parse_error { errcode::numeric_overflow };

			this->tag = this->tag*10 + (ch-'0');
		}

		throw parse_error { errcode::end_of_stream };
	}


	const tag_value_iterator_value_type<Iterator>&  dereference() const
	{
		if(!valid)
			throw errcode { errcode::invalid_iterator_state };
		return *this;
	}
	template<class Other>
	bool equal(const Other& a) const
	{
		return (a.valid && valid) ? ( (a.begin==begin) && (a.end == end) ) : (a.valid==valid);
	}

	Iterator begin;
	Iterator end;
	SeparatorType separator;
	bool valid;
};


template<typename InputIterator>
void parseMessage(InputIterator first, InputIterator last, char separator)
{
	for(tag_value_iterator it{first, last}; it != tag_value_iterator{}; ++it)
	{
		const tag_value_iterator::value_type& vt = *it;
		std::cout << "tag=" << vt.tag << " value=" << std::string { vt.first, vt.second } << '\n';
	}
}

int main()
{

	//MessageType t = NewOrderSingle::messageType;
	//std::cout << "type=" << messageTypeToCStr(t) << std::endl;

	std::string message =
		"8=WHL.1.0|9=363|35=Q|34=230827|52=20131113-10:00:12.455|97=N|10=002|";
	parseMessage(message.begin(), message.end(), '|');




	//std::pair<int, std::string::iterator> ret = parseTag(message.begin(), message.end());
	//std::cout << "tag=" << ret.first << std::endl;
	return 0;

}
