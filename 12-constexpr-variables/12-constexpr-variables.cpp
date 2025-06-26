#include <iostream>

int GetRandomInt() {
	return std::rand();
}

int main() {

	// a is an int whose value is known at compile time
	constexpr int a{ 0 };
	std::cout << "a: " << a << std::endl;

	//b same as a
	int constexpr b{ 1 };
	std::cout << "b: " << b << std::endl;

	//a const variable might be constexpr (this is the case)
	const int c{ 1 };
	std::cout << "c: " << c << std::endl;
	
	//or not (c is not known at compile time)
	const int d{ GetRandomInt()};
	std::cout << "d: " << d << std::endl;

	//a constexpr variable can be initialized with another constexpr
	constexpr int e(a);
	std::cout << "e: " << e << std::endl;

	//or with a const that is actually constexpr
	constexpr int f(c);

	//but not with a const that is not constexpr
	//constexpr int f(d); ERROR, d not known

	//constexpr variables have an address in memory
	std::cout << "&a: " << &a << std::endl;

	//but it is not known at compile time.
	// You can have pointers to constexpr but they cannot hold 
	// the address of constexpr variables
	 constexpr int* ptr_to_constexpr{ nullptr };
	 //constexpr int* ptr_to_constexpr{ &a }; ERROR, address of a not known at compile time

}