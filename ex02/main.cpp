#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int randVal = std::rand();

	if (randVal % 3 == 0)
		return new A;
	else if (randVal % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN  << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN  << "C" << RESET << std::endl;
	else
		std::cout << RED << "Unknown type!" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << GREEN << "A" << RESET << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << GREEN  << "B" << RESET << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		C& c= dynamic_cast<C&>(p);
		(void) c;
		std::cout << GREEN  << "C" << RESET << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	std::cout << RED << "Unknown type!" << RESET << std::endl;
}

int main(void)
{
	Base* base = generate();

	std::cout << "(Base* p)generate type: " << std::flush;
	identify(base);
	std::cout << "(Base& p)generate type: " << std::flush;
	identify(*base);

	delete base;
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
