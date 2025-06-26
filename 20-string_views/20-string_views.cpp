#include <iostream>
#include <string_view>
#include <ranges>
#include <iomanip>
#include <algorithm>

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
}
