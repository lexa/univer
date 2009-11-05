#include <iostream>
#include "filter.hpp"

int main()
{
	Filter f(10);
	FILTER_TYPE x, ideal;
	while (!std::cin.eof())
	{
		std::cin >> x >> ideal;
		std::cout << f.next(x, ideal) << std::endl;
	}


	return 0;
}

