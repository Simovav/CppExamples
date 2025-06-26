#include <iostream>

int GetSomeIntValue() {
	return 4;
}

int main()
{
	int data = 3;
	int* data_address = &data;
	int& data_ref = data;
	int(*fun_ptr)(void) = GetSomeIntValue;

	std::cout << "the value of data is " << data << ".\n";
	std::cout << "the address of data is " << &data << ".\n";
	std::cout << "the value of data_ref is " << data_ref << ".\n";
	std::cout << "the address of data_ref is " << &data_ref << ".\n";
	std::cout << "the address of GetSomeIntValue is " << fun_ptr << ".\n";

	//cpp23
	/*
	std::println("the value of data is {}.", data);
	std::println("the address of data is {}.", static_cast<void*>(data_address));
	std::println("the value of data_ref is {}.", data_ref);
	std::println("the address of data_ref is {}.", static_cast<void*>(&data_ref));
	std::println("the address of GetSomeIntValue is {}.", static_cast<void*>(fun_ptr));
	*/

	int copy_value = GetSomeIntValue(); //OK
	//int& ref = GetSomeIntValue(); NOT OK, dangling reference
	int&& ref = GetSomeIntValue(); //OK, extends the duration of the temporary value

}