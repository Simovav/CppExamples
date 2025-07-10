#include <malloc.h>
#include <iostream>
void* operator new(size_t n) noexcept(false) {
	auto p = std::malloc(n);
	std::cout << "Allocating " << n << " bytes at " << p << std::endl;
	return p;
}

void operator delete(void* p) {
	std::cout << "Deallocating memory at " << p << std::endl;
	std::free(p);
}

class BigObject
{
public:
	BigObject() : data(new int[1000000]) {
	}

	~BigObject() {
		delete[] data;
	}

	BigObject(const BigObject& other) : data(new int[1000000]) {
		if (this != &other) {
			std::copy(other.data, other.data + 1000000, data);
		}
	}

	BigObject(BigObject&& other) noexcept : data(other.data) {
		data = other.data;
		other.data = nullptr;
	}

	BigObject& operator=(const BigObject& other) {
		BigObject temp(other); // copy constructor
		swap(temp); // swap with the temporary object
		return *this;
	}

	BigObject& operator=(BigObject&& other) noexcept {
		BigObject temp(std::move(other)); // move constructor
		swap(temp); // swap with the temporary object
		return *this;
	}

	void swap(BigObject& other) noexcept {
		using std::swap;
		swap(data, other.data);
	}
private:
	int* data{ nullptr };
};

BigObject createBigObject() {
	return BigObject(); // Move constructor will be called here
}

int main()
{
	BigObject obj1; // Allocates memory for data
	BigObject obj2 = obj1; // Copy constructor called
	BigObject obj3 = std::move(obj1); // Move constructor called
	obj2 = obj3; // Copy assignment operator called
	obj2 = std::move(obj3); // Move assignment operator called

	BigObject obj4 = createBigObject(); // RVO
	obj4 = createBigObject();

	return 0;

}