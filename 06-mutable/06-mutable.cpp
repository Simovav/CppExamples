#include <vector>
#include <mutex>
#include <future>
#include <iostream>
#include <ranges>

class ThreadSafeSimpleVector {
private:
    std::vector<int> m_values;
    mutable std::mutex m_lock;

public:
    void push_back(int val) {
        std::lock_guard<std::mutex> lock(m_lock);
        m_values.push_back(val);
    }

    size_t size() const { //this is a const method
        std::lock_guard<std::mutex> lock(m_lock);//this would not be allowed if m_lock was not mutable
        return m_values.size();
    }

    void print() const {
        std::lock_guard<std::mutex> lock(m_lock);
        //cpp20
        std::ranges::copy(m_values, std::ostream_iterator<int>(std::cout, ", "));
        //cpp23
        //std::println("{}, ", m_values);
    }
};

int main() {
    ThreadSafeSimpleVector sv;
    auto task1 = std::async(std::launch::async, [&]() {
        for (int k = 0; k < 4000; ++k)
            sv.push_back(k);
        });
    auto task2 = std::async(std::launch::async, [&]() {
        for (int k = 0; k < 4000; ++k)
            sv.push_back(k);
        });

    task1.wait();
    task2.wait();

    std::cout << "the size of sv is " << sv.size() << ".\n";
    sv.print();
}