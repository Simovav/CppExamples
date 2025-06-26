#include <print>

constexpr int getValue() {
	if consteval {
		return 1;//this executes if the call happens at compile time
	}
	else {
		return -1;//only this branch is generated for runtime
	}
}

consteval int fun() { return 1; }
int  fallback() { std::println("fallback"); return -1; }

constexpr int routine() {
	if consteval {
		return fun();
	}
	else {
		return fallback();
	}
}

int main() {
	int a = getValue();
	std::println("a = {}", a); //prints -1

	constexpr int b = getValue();
	std::println("b = {}", b); //prints 1

	int not_cexpr = routine();
	constexpr int a_cexpr = routine();
}