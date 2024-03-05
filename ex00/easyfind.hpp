#ifndef DEF_EASYFIND
#define DEF_EASYFIND

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

class NotFoundException : public std::exception
{
	public :
		virtual const char *what() const throw() { return("Value not found in container"); };
};

// Return the first occurrence of the second parameter in the first parameter.
template<typename T>
typename T::const_iterator easyfind(T const& container, int const& value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
