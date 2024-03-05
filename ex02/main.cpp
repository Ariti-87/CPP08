#include "MutantStack.hpp"

int main()
{
	std::cout << GREEN << "Subject's main" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;

	std::cout << CYAN << "My main - MutantStack with list " << RESET << std::endl;
	MutantStack<int, std::list<int> > mlist;
	mlist.push(5);
	mlist.push(17);
	std::cout << mlist.top() << std::endl;
	mlist.pop();
	std::cout << mlist.size() << std::endl;
	mlist.push(3);
	mlist.push(5);
	mlist.push(737);
	mlist.push(0);
	MutantStack<int, std::list<int> >::iterator it2 = mlist.begin();
	MutantStack<int, std::list<int> >::iterator ite2 = mlist.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	MutantStack<int, std::list<int> > s2(mlist);

	std::cout << std::endl;

	std::cout << MAGENTA << "My main - list " << RESET << std::endl;
	std::list<int> mlist2;
	mlist2.push_back(5);
	mlist2.push_back(17);
	std::cout << mlist2.back() << std::endl;
	mlist2.pop_back();
	std::cout << mlist2.size() << std::endl;
	mlist2.push_back(3);
	mlist2.push_back(5);
	mlist2.push_back(737);
	mlist2.push_back(0);
	std::list<int>::iterator it3 = mlist2.begin();
	std::list<int>::iterator ite3 = mlist2.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::list<int> s3(mlist2);

	return 0;
}
