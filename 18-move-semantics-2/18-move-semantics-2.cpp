// 18-move-semantics-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

bool signal = false;

class LoudMan {
public:
	LoudMan() {
		if (signal) { std::cout << "LoudMan created\n"; }
	}
	~LoudMan() {
		if (signal) { std::cout << "LoudMan destroyed\n"; }
	}
	LoudMan(const LoudMan&) {
		if (signal) { std::cout << "LoudMan copied\n"; }
	}
	LoudMan(LoudMan&&) noexcept {
		if (signal) { std::cout << "LoudMan moved\n"; }
	}
	LoudMan& operator=(const LoudMan&) {
		if (signal) { std::cout << "LoudMan copy assigned\n"; }
		return *this;
	}
	LoudMan& operator=(LoudMan&&) noexcept {
		if (signal) { std::cout << "LoudMan move assigned\n"; }
		return *this;
	}
};

class WrongLoudMan {
public:
	WrongLoudMan() {
		if (signal) { std::cout << "WrongLoudMan created\n"; }
	}
	~WrongLoudMan() {
		if (signal) { std::cout << "WrongLoudMan destroyed\n"; }
	}
	WrongLoudMan(const WrongLoudMan&) {
		if (signal) { std::cout << "WrongLoudMan copied\n"; }
	}

	WrongLoudMan(WrongLoudMan&&) {
		if (signal) { std::cout << "WrongLoudMan moved\n"; }
	}
	WrongLoudMan& operator=(const WrongLoudMan&) {
		if (signal) { std::cout << "WrongLoudMan copy assigned\n"; }
		return *this;
	}
	WrongLoudMan& operator=(WrongLoudMan&&) {
		if (signal) { std::cout << "WrongLoudMan move assigned\n"; }
		return *this;
	}

};

LoudMan createLoudMan() {
	LoudMan lm;
	return lm; // This will invoke the move constructor if available
}

int main()
{
	signal = true;
	LoudMan lm1;
	lm1 = createLoudMan(); // This will invoke the move assignment operator if available
	system("cls");
	std::vector<LoudMan> vec(5);
	system("cls");
	vec.resize(6); // This will invoke the move constructor for the new element
	system("cls");
	std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
	vec.emplace_back(); // This will invoke the move constructor for the new element
	system("cls");
	vec.push_back(createLoudMan());
	system("cls");

	std::vector<WrongLoudMan> vec2(5);
	system("cls");
	vec2.resize(6); // This will not invoke the move constructor for the new element, because it is not noexcept
}
