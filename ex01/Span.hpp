#ifndef DEF_SPAN
#define DEF_SPAN

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define VIOLET "\033[35m"
#define GREEN "\033[32m"
#define LGREEN "\033[92m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
#include <numeric>

class Span
{
	public:
		Span(unsigned int N);
		Span(Span const& src);
		~Span();
		Span &operator=(Span const& src);

		void addNumber(int nb);

		template<typename I>
		void addNumber(I first, I last);

		int shortestSpan() const;
		int longestSpan() const;

	class SpanFullException : public std::exception
	{
		public:

		virtual const char *what() const throw();
	};

	class SpanCalculException : public std::exception
	{
		public:

		virtual const char *what() const throw();
	};

	private:
		std::vector<int> _numbers;
		unsigned int _sizeMax;

		Span();
};

template<typename I>
void Span::addNumber(I first, I last)
{
	if (std::distance(first, last) + _numbers.size() > _sizeMax)
		throw (SpanFullException());
	_numbers.insert(_numbers.end(), first, last);
}


#endif

