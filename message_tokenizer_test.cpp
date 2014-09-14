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
	numeric_overflow,
	missing_tag,
	not_a_number
};

struct parse_error
{
	parse_error(errcode errc) {}
};

template<typename InputIterator>
std::pair<int, InputIterator> parseTag(InputIterator first, InputIterator last)
{
	if(first == last)
		throw parse_error { errcode::empty_range };

	if(*first == '=')
		throw parse_error { errcode::missing_tag };

	int ch = *first++;

	if(!std::isdigit(ch))
		throw parse_error { errcode::not_a_number };
	
	int tag= ch - '0';	// TODO: may not be portable

	for(; first != last; ++first)
	{
		ch = *first;

		if(ch == '=')
		{
			return std::make_pair(tag, ++first);
		}

		if(!std::isdigit(ch))
			throw parse_error { errcode::not_a_number };

		if(tag  > (std::numeric_limits<int>::max() - (ch-'0')) / 10)
			throw parse_error { errcode::numeric_overflow };

		tag = tag*10 + (ch-'0');
	}

	throw parse_error { errcode::end_of_stream };
}

template<typename InputIterator>
void parseMessage(InputIterator first, InputIterator last, char separator)
{
	while(first != last)
	{
		std::pair<int, InputIterator> ret = parseTag(first, last);
		first = std::find(ret.second, last,  separator);
		if(first == last)
			throw parse_error { errcode::end_of_stream };

		{
			std::cout << "tag=" << ret.first << " value=" << std::string { ret.second, first } << '\n';
		}

		++first;
	}
}

template<typename InputIterator>
struct tag_value_iterator_value_type
{
	int tag {};
	InputIterator first {};
	InputIterator second {};
};

template<typename InputIterator, typename SeparatorType>
class tag_value_iterator : public tag_value_iterator_value_type<InputIterator>
{
public:
	tag_value_iterator(InputIterator begin, InputIterator end, SeparatorType separator = 1)
		: begin { begin }, end { end }, separator{separator}, valid {begin != second}
	{
		if(valid)
			increment();
	}

	tag_value_iterator() : begin{}, end{}, separator{1}, valid(false) {}

private:
	void increment()
	{
		if(!valid)
			throw errcode { invalid_iterator };
		if(begin == end)
			valid = false;
		std::pair<int, InputIterator> ret = parseTag(begin, end);
		begin = std::find(ret.second, end,  separator);
		if(begin == end)
			throw parse_error { errcode::end_of_stream };
	}

	const tag_value_iterator_value_type&  dereference() const
	{
		if(!valid)
			throw errcode { invalid_iterator };
		return *this;
	}
	template<class Other>
	bool equal(const Other& a) const
	{
		return (a.valid && valid) ? ( (a.begin==begin) && (a.end == end) ) : (a.valid==valid);
	}

	InputIterator begin;
	InputIterator end;
	SeparatorType separator;
	bool valid;
};

int main()
{

	//MessageType t = NewOrderSingle::messageType;
	//std::cout << "type=" << messageTypeToCStr(t) << std::endl;

	std::string message =
		"8=WHL.1.0|9=363|35=Q|34=230827|52=20131113-10:00:12.455|97=N|10=002|";
	parseMessage(message.begin(), message.end(), '|');

	tag_value_iterator it(message.begin(), message.end());


	//std::pair<int, std::string::iterator> ret = parseTag(message.begin(), message.end());
	//std::cout << "tag=" << ret.first << std::endl;
	return 0;

}
