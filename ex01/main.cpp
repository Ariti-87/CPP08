#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp1(4);
	int numbers[] = {6, 3, 17, 9, 11};
	// converting an array to a vector
	std::vector<int> nbToAdd(numbers, numbers + sizeof(numbers) / sizeof(int));
	try
	{
		sp1.addNumber< std::vector<int> >(nbToAdd.begin(), nbToAdd.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span sp2(std::numeric_limits<int>::max());
	try
	{
		sp2.addNumber< std::vector<int> >(nbToAdd.begin(), nbToAdd.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
