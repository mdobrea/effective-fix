#include <iostream>
#include <vector>

#include <algorithm>
#include <iterator> // iterator_traits
#include <limits>	// numeric_limits

enum class tag
{
	begin_string = 8,
	body_length = 9
};
enum class errcode
{
	empty_range=1,
	end_of_stream,
	invalid_iterator_state,
	numeric_overflow,
	missing_tag,
	not_a_number
};

struct parse_error
{
	parse_error(errcode errc) : errc{errc} {}
	errcode errc;
};


template<typename Iterator>
struct tag_value
{
	int tag {};
	Iterator first {};
	Iterator second {};
};



template<typename Iterator>
std::ostream& operator<<(std::ostream& os, const tag_value<Iterator>& tv)
{
	std::cout << '{' << tv.tag << "," << std::string { tv.first, tv.second } << '}';
	return os;
}

template<typename Iterator>
class tag_value_iterator : 	public std::iterator<
								typename std::iterator_traits<Iterator>::iterator_category,
								tag_value<Iterator>>,
							private tag_value<Iterator>
{
public:
	tag_value_iterator(
		Iterator begin,
		Iterator end,
		typename std::iterator_traits<Iterator>::value_type separator = 1)
		: begin{begin}, end{end}, separator{separator}, valid {begin != end}
	{
		if(valid)
			increment();
	}

	tag_value_iterator() : begin{}, end{}, separator{1}, valid(false) {}

	const tag_value_iterator<Iterator>& operator++()
	{
		increment();
		return *this;
	}

	bool operator==(const tag_value_iterator<Iterator>& a) const
	{
		return (a.valid && valid) ? ( (a.begin==begin) && (a.end == end) ) : (a.valid==valid);
	}

	bool operator!=(const tag_value_iterator<Iterator>& a) const
	{
		return !(*this == a);
	}

	tag_value<Iterator>& operator*() { return *this; };
	const tag_value<Iterator>& operator*() const { return *this; };

private:
	void increment()
	{
		if(!valid)
			throw errcode { errcode::invalid_iterator_state };
		if(begin == end)
		{
			valid = false;
			return;
		}
		parseTag();
		this->first = begin;
		this->second = std::find(begin, end, separator);
		if(this->second == end)
		{
			throw parse_error { errcode::end_of_stream };
		}
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

	Iterator begin;
	Iterator end;
	typename std::iterator_traits<Iterator>::value_type separator;
	bool valid;
};

template<typename Iterator, typename Function>
Function for_each(Iterator first, Iterator last, Function function, typename std::iterator_traits<Iterator>::value_type separator)
{
	std::for_each(tag_value_iterator<Iterator>{first, last, separator},
		tag_value_iterator<Iterator>{},
		function);
}

template<typename Iterator>
void dumpMessage(Iterator first, Iterator last, typename std::iterator_traits<Iterator>::value_type separator, char recordSeparator)
{
	for_each(first, last, [](const tag_value<Iterator>& cv) { std::cout << cv << recordSeparator; }, separator);
}

// todo - generate this function
template<typename Iterator>
void f(const tag_value<Iterator>& cv)
{
	switch(cv.tag)
	{
	case tag::begin_string: // TODO - check if correct, extract version info
		break;
	case tag::body_length: // TODO - check if we read enough data (it checks the distance(begin, end) of the message)
		break;
	}
}

int main()
{

	//MessageType t = NewOrderSingle::messageType;
	//std::cout << "type=" << messageTypeToCStr(t) << std::endl;

	std::string message =
		"8=WHL.1.0|9=363|35=Q|34=230827|52=20131113-10:00:12.455|97=N|10=002|";
	try
	{
		dumpMessage(message.begin(), message.end(), '|', ',');
	}
	catch(const parse_error& e)
	{
		std::cout << "error=" << static_cast<int>(e.errc) << '\n';
	}
	//std::pair<int, std::string::iterator> ret = parseTag(message.begin(), message.end());
	//std::cout << "tag=" << ret.first << std::endl;
	return 0;

}

