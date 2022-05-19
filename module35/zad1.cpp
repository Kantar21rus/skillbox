#include <iostream>
#include <initializer_list>



int main()
{
	std::initializer_list<int> il = {1, 2, 3, 4, 5};
	for (auto i : il)
	{
		std::cout << i << "\n";
	}
}
