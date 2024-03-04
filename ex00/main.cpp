#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(1);
	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, 1);
		std::vector<int>::const_iterator it_begin = vec.begin();
		std::cout << "Found value " << *it << " at position " << std::distance(it_begin, it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator it = easyfind(vec, 42);
		std::cout << "Found value " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
