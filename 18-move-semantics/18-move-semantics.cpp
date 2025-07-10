#include <iostream>

std::string Get() { return "Hello i'm an rvalue"; }
void ConsumeRValue(std::string&& str) {};

void ConsumerOne(std::string&& str) {};

//Does this work?
void ConsumerTwo(std::string&& str) {
	ConsumerOne(static_cast<std::string&&>(str)); //here str is an lvalue, ConsumerOne does not accept it
}

class BigObject {};
class SomeClass {
private:
	BigObject m_big_obj;
public:
	//Different read methods:
	const BigObject& data() const& noexcept { std::cout << "overload 1\n"; return m_big_obj; }
	BigObject& data() & noexcept { std::cout << "overload 2\n";  return m_big_obj; }
	BigObject&& data() && noexcept { std::cout << "overload 3\n";  return std::move(m_big_obj); }
	//cpp23
	//template<typename Self>
	//auto&& data(this Self&& self) { return std::forward<Self>(self).m_big_obj; }
};

int main()
{
	ConsumeRValue(Get());

	std::string the_string = Get();
	//ConsumeRValue(the_string);

	std::string&& the_string_ref = Get();
	//ConsumeRValue(the_string_ref);

	SomeClass a;
	a.data();

	const SomeClass b;
	b.data();

	SomeClass().data();
}
