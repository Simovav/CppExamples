#include <type_traits>
#include <iostream>

enum class ColorChannel : uint8_t {
	Red,
	Green,
	Blue,
	Alpha

};


int main()
{
	std::cout << "ColorChannel underlying type is: " << typeid(typename std::underlying_type<ColorChannel>::type).name() << std::endl;
	std::cout << "its size is: " << sizeof(ColorChannel) << " bytes." << std::endl;

}
