#include "C.hpp"

Base	*generate(void)
{
	std::srand(time(0));
	int classID = ((rand() % 3));

	if (classID == 0)
		return (new A());
	if (classID == 2)
		return (new B());
	return (new C());
}

void	identify(Base *p)
{
	if (!p)
		std::cout << "No base find for this Base pointer ! " << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "Base pointer is of type A ! " << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Base pointer is of type B ! " << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Base pointer is of type C ! " << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base pointer is of type A ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base pointer is of type B ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base pointer is of type C ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
}

int	main(void)
{
	Base *p = generate();

	identify(*p);
	identify(p);

	delete p;

	Base *p2 = generate();

	identify(*p2);
	identify(p2);

	delete p2;

	return 0;
}