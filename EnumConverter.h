#ifndef ENUMCONVERTER_H
#define ENUMCONVERTER_H
#include <functional>
#include <type_traits>
template<typename T, typename = typename std::enable_if_t<std::is_enum_v<typename std::decay_t<T>>>>
struct EnumConverter {
	using Converter = std::function<T(std::string)>;
	Converter converter;
public:
	explicit EnumConverter(const Converter& c) :converter(c) {

		//str = STR::x
		/*
		-what we need to do, is construct a reverse enum converter.
		*/
	}
	T operator()(const std::string& str) {
		auto tmp = str;
		for (auto& c : tmp) {
			c = std::toupper(c);
		}
		return converter(std::move(tmp));
	}

};
#endif