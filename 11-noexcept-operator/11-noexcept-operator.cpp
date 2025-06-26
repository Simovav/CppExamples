#include <iostream>

void fun1() noexcept(true) {} //does not throw
void fun2() noexcept(false) {} //may throw


void inner_fun() noexcept(true) {} //does not throw

void outer_fun() noexcept(noexcept(inner_fun())) { //this is noexcept if inner_fun is noexcept
	inner_fun();
	inner_fun();
	inner_fun();
}

int main() {
	bool is_fun1_noexcept = noexcept(fun1());
	std::cout << "fun1 is noexcept(" << std::boolalpha << is_fun1_noexcept << ").\n";

	bool is_fun2_noexcept = noexcept(fun2());
	std::cout << "fun2 is noexcept(" << std::boolalpha << is_fun2_noexcept << ").\n";

	bool is_inner_fun_noexcept = noexcept(inner_fun());
	std::cout << "inner_fun is noexcept(" << std::boolalpha << is_inner_fun_noexcept << ").\n";

	bool is_outer_fun_noexcept = noexcept(outer_fun());
	std::cout << "outer_fun is noexcept(" << std::boolalpha << is_outer_fun_noexcept << ").\n";
}
