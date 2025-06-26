#include <iostream>
#include <chrono>

int main()
{
	std::cout << "Executing non volatile iteration\n";
	auto startTime = std::chrono::high_resolution_clock::now();

	constexpr int MAX_ITER = 1000000000;
	int j = 0;
	for (size_t k = 0; k < MAX_ITER; ++k)
		j = 1; //optimized away

	auto endTime = std::chrono::high_resolution_clock::now();

	auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

	std::cout << "time: " << duration_ns.count() << " ns.\n";
	//cpp23
	//std::println("time: {} ns.", duration_ns.count());

	std::cout << "Executing volatile iteration\n";
	//std::println("Executing volatile iteration");
	startTime = std::chrono::high_resolution_clock::now();

	volatile int vol_j = 0;
	for (size_t k = 0; k < MAX_ITER; ++k)
		vol_j = 1; //not optimized

	endTime = std::chrono::high_resolution_clock::now();

	duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	std::cout << "time: " << duration_ns.count() << " ns.\n";
	//cpp23
	//std::println("time: {} ns", duration_ns.count());
}
