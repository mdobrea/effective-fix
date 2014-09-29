
#include <effective_fix/tag_value.hpp>
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

