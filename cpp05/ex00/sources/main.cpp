#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test("Louis", 1);

	std::cout << test << std::endl;

	Bureaucrat test2("Laurent", 200);
	
	std::cout << test2 << std::endl;

	test2.gradeDecrement();

	test2 = test;

	std::cout << test2 << std::endl;

	test2.gradeDecrement();

	Bureaucrat test3(test2);

	std::cout << test3 << std::endl;

	std::cout << "###########################################" << std::endl;

	test3.gradeIncrement();

	std::cout << test3 << std::endl;

	test3.gradeDecrement();

	std::cout << test3 << std::endl;

	test3.gradeIncrement();

	std::cout << test3 << std::endl;

	test3.gradeIncrement();

	std::cout << test3 << std::endl;

	return (0);
}