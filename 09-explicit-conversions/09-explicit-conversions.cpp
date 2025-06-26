#include <iostream>

struct implicit_int_wrapper {
	int val;
	operator int() const { return val; } //class can be implicitly converted to int
};

struct explicit_int_wrapper {
	int val;
	explicit operator int() const{ return val; } //the conversion must be done through static_cast
};

void printInt(int a) {
	std::cout << "the integer is: " << a << ".\n";
}

int main() {
	implicit_int_wrapper impl{ -1 };
	explicit_int_wrapper expl{ 1};

	printInt(impl);//Implicit conversion to int
	printInt(static_cast<int>(expl));//Explicit cast required
}