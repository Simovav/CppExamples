#include <iostream>

constexpr int add(int a, int b) noexcept {
	return a + b;
};

int main() {
	int a = 1;
	int b = 2;
	constexpr int c = 3;

	std::cout << add(a, b) << std::endl;//runtime
	std::cout << add(2, 3) << std::endl;//runtime

	constexpr int d = add(1, c); //compile time
}