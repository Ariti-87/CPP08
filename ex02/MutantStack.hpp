#ifndef DEF_MUTANTSTACK
#define DEF_MUTANTSTACK

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
#include <stack>
#include <vector>
#include <algorithm>
#include <list>

/*
 * MutantStack is a custom stack implementation that extends the functionality
 * of std::stack to include iterator access to the underlying container.
 * It allows for more flexible manipulation of stack elements.
 *
 * T: The type of elements stored in the stack.
 * Container: The underlying container type, defaulting to std::deque<T>.
 */
template <typename T, typename Container = std::deque< T > >
class MutantStack : public std::stack< T, Container >
{
	public:
		MutantStack() {};
		MutantStack(MutantStack & src) : std::stack< T, Container >(src) {}
		~MutantStack() {}
		MutantStack & operator=(MutantStack & src)
		{
			if (this != &src)
				std::stack< T, Container >::operator=(src);
			return (*this);
		}
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }

		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }

		reverse_iterator rbegin() { return (this->c.rbegin()); };
		reverse_iterator  rend() { return (this->c.rend()); };

		const_reverse_iterator rbegin() const { return (this->c.rbegin()); };
		const_reverse_iterator rend() const { return (this->c.rend()); };
};

#endif

