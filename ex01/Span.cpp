#include "Span.hpp"

Span::Span()
{
	std::cout << CYAN << "Default Span" << RESET << " has been created" << std::endl;
}

Span::Span(unsigned int N) : _sizeMax(N)
{
	std::cout << CYAN << "Span" << RESET << " has been created" << std::endl;
}

Span::Span(Span const& src) : _numbers(src._numbers), _sizeMax(src._sizeMax)
{
	std::cout << CYAN << "Copy Span " << RESET << " has been created" << std::endl;
}

Span::~Span()
{
	std::cout << CYAN << "Span " << RESET << " has been destroyed" << std::endl;
}

Span & Span::operator=(Span const& src)
{
	if (this != &src)
	{
		_sizeMax = src._sizeMax;
		_numbers = src._numbers;
	}
	return *this;
}

void Span::addNumber(int nb)
{
	if (_numbers.size() == _sizeMax)
		throw (SpanFullException());
	_numbers.push_back(nb);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (SpanCalculException());
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> diff(_numbers);
	std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());
	for(unsigned int i = 0; i < diff.size(); i++)
		diff[i] = std::abs(diff[i]);
	return *std::min_element(diff.begin(), diff.end());
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (SpanCalculException());
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Span is full. Cannot add more numbers");
}

const char *Span::SpanCalculException::what() const throw()
{
	return ("Not enough numbers to calculate span");
}

