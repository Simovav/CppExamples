#include <iostream>
struct selector {
	int a;
	int b;

	template<int idx>
	constexpr int get() const {
		if constexpr (idx == 0)
			return a;
		else if constexpr (idx == 1)
			return b;
		else
			throw std::out_of_range();
	}

};

int main() {
	selector s(-1, 1);
	std::cout << "a = " << s.get<0>() << std::endl;
	std::cout << "b = " << s.get<1>() << std::endl;
}