#include <iostream>
#include "filter.hpp"

int main()
{
	Filter f(5);
	FILTER_TYPE x, ideal;
	while (!std::cin.eof())
	{
		std::cin >> x >> ideal;
		std::cout << f.next(x, x/2) <<  "  " << f.result() << std::endl;
//		std::cout.flush();
	}

	// std::cout << f.next(1, 1) << std::endl;
	// std::cout << f.next(1, 1) << std::endl;
	// std::cout << f.next(1, 1) << std::endl;

	return 0;
}

