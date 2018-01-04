#include <iostream>
#include <utility>
#include <tuple>

struct Currency
{
	using ValueType=std::string;
	Currency(const ValueType& value_) : value(value_) {} 
	ValueType value;
};

struct MarketID
{
	using ValueType=std::string;
	MarketID(const ValueType& value_) : value(value_) {} 
	ValueType value;
};

struct SecurityID 
{
	using ValueType=std::string; 
	SecurityID(const ValueType& value_) : value(value_) {} 
	ValueType value;
};

struct SecurityIDSource
{
	using ValueType=std::string; 
	SecurityIDSource(const ValueType& value_) : value(value_) {} 
	ValueType value;
};

using SecurityDefinition=std::tuple<MarketID, SecurityIDSource, SecurityID, Currency>; 

template<std::size_t I = 0, typename OstreamT, typename... Tp>
typename std::enable_if<I == sizeof...(Tp), void>::type print(OstreamT& out, const std::tuple<Tp...>& tp)
{
	out << "}";
}

template<std::size_t I = 0, typename OstreamT, typename... Tp>
typename std::enable_if<I < sizeof...(Tp), void>::type print(OstreamT& out, const std::tuple<Tp...>& tp)
{
	if(I==0)
		out << '{';
	else
		out << ',';
	out << std::get<I>(tp).value;
	print<I+1, OstreamT, Tp...>(out, tp);
}

template<typename OstreamT, typename... Tp>
OstreamT& operator<<(OstreamT& out, const std::tuple<Tp...>& tp)
{
	print(out, tp);
}

int main()
{
	SecurityDefinition sd(std::string{"XETR"}, std::string{"4"}, std::string{"DE1234567890"}, std::string{"EUR"});
 	std::cout << sd << '\n';
	return 0;
}
