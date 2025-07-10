#include <iostream>
#include <string_view>
#include <ranges>
#include <iomanip>
#include <algorithm>
#include <vector>

int main()
{
	std::string szOriginal("prfxThis is a string with a prefix");
	std::string_view szView(szOriginal);

	//"This is a string with a prefix"
	szView.remove_prefix(4); //shrinks the view by moving its start forward, it is just a pointer shift.

	auto subView = szView.substr(10, 6);

	//----------------------------------------------------------------------
	std::string_view szEntityNameOne("NURBS:G(1)");
	std::string_view szEntityNameTwo("PATH:Lay1\\Path1");

	std::cout << szEntityNameOne << (szEntityNameOne.find("NURBS") != std::string_view::npos ? " is" : " is not")
		<< " a NURBS\n";
	std::cout << szEntityNameOne << (szEntityNameOne.find("PATH") != std::string_view::npos ? " is" : " is not")
		<< " a PATH\n";
	std::cout << szEntityNameTwo << (szEntityNameTwo.find("NURBS") != std::string_view::npos ? " is" : " is not")
		<< " a NURBS\n";
	std::cout << szEntityNameTwo << (szEntityNameTwo.find("PATH") != std::string_view::npos ? " is" : " is not")
		<< " a PATH\n\n";



	//----------------------------------------------------------------------
	std::string szOriginal_2("this ; is; a; very; very ; long; string ;with; many; characters; that; is; quite; expensive; to; copy...");

	std::string_view szView_2(szOriginal_2); //This is just a view of the data in szOriginal

	auto split_view = std::views::split(szView_2, ';');
	for (auto&& item : split_view) {
		std::string_view sv(item.begin(), item.end());
		std::cout << sv << std::endl;

	}

	std::cout << "------------------" << std::endl;

	auto split_view_2 = szView_2 | std::views::split(';');

	for (auto&& item : split_view) {
		std::string_view sv(item.begin(), item.end());
		std::cout << sv << std::endl;

	}

	std::cout << "------------------" << std::endl;


	std::ranges::for_each(szView_2 | std::views::split(';'), [](auto&& item) {
		std::string_view sv(item.begin(), item.end());

		auto first_nonspace_pos = sv.find_first_not_of(' ');
		if (first_nonspace_pos != std::string_view::npos)
			sv.remove_prefix(first_nonspace_pos);//removes leading spaces

		auto last_nonspace_pos = sv.find_last_not_of(' ');
		if (last_nonspace_pos != std::string_view::npos)
			sv.remove_suffix(sv.size() - last_nonspace_pos - 1);//removes trailing spaces

		std::cout << sv << std::endl; }
	);

	std::string_view szBadView(std::string("this object dies"));
	std::cout << "look at this bad view: " << szBadView << std::endl;


	std::vector<int> vec{ 1, 2, 0, 3, 4, 5, 0, 6, 7, 3, 8, 0, 9, 10 };
	auto filtered_vec = vec | std::views::filter([](int a) {return a != 0; });
	for (auto&& item : filtered_vec) {
		std::cout << item << " ";
	}

	std::cout << "------------------" << std::endl;


	auto filtered_split_vec = vec | std::views::filter([](int a) {return a != 0; }) | std::views::split(3);
	for (auto&& item : filtered_split_vec) {
		std::cout << "(";
		for (auto&& subitem : item) {
			std::cout << subitem << " ";
		}
		std::cout << ")" << std::endl;
	}
}
