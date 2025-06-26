#include <iostream>

class ImplicitValue {
private:
    int m_val{ 0 };
public:
    ImplicitValue(int val) :m_val(val) {}
};

void SomeImplicitFunction(ImplicitValue v) { std::cout<<"function 1 called.\n"; }
//void SomeImplicitFunction(int v) { std::println("function 2 called."); }

class ExplicitValue {
private:
    int m_val{ 0 };
public:
    explicit ExplicitValue(int val) :m_val(val) {}
};

void SomeFunction(ExplicitValue v) {}

int main() {
    SomeImplicitFunction(2);
    SomeFunction(ExplicitValue(2)); //implicit conversion through the ImplicitValue(2) constructor. Confusing
    //SomeFunction(2);
}