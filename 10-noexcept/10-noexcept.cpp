#include <iostream>

//no throw statement can escape this funcion
void noexcept_function() noexcept {
	try {
		throw 1;
	}
	catch (...) {//the catch is within the function, nothing escapes

	}
}

void crasher() noexcept {
	throw 1;
}

void explicit_noexcept() noexcept(true) {} //does not throw

void explicit_except() noexcept(false) {} //may throw


int main() {
	std::cout << "calling..." << std::endl;
	noexcept_function();
	std::cout << "call done." << std::endl;

	try {
		std::cout << "invoking crasher..." << std::endl;
		crasher();
	}
	catch (...) {
		std::cout << "crash prevented." << std::endl;
	}
}