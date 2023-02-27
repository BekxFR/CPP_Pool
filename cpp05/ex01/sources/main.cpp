#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test("Louis", 1); // HIGH LEVEL

	std::cout << test << std::endl;

	Bureaucrat test2("Laurent", 200); // LOW LEVEL
	
	std::cout << test2 << std::endl;

	test2.gradeDecrement();

	test2 = test;

	std::cout << test2 << std::endl;

	test2.gradeDecrement();

	Bureaucrat test3(test2); // HIGH LEVEL

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

	std::cout << "###########################################" << std::endl;
{
	Form form1("High Form", 1, 1);
	std::cout << form1 << std::endl;

	Form form2("Low Form", 150, 150);
	std::cout << form2 << std::endl;

	Form form3("Unvailable Form", 160, 0);
	std::cout << form3 << std::endl;

	std::cout << "###########################################" << std::endl;

	test2.signForm(form1); // LOW and HIGH NOK
	std::cout << form1 << std::endl;

	std::cout << "###########################################" << std::endl;

	test3.signForm(form2); // HIGH AND LOW OK
	std::cout << form2 << std::endl;

	std::cout << "###########################################" << std::endl;

	test2.signForm(form3); // LOW AND NOK NOK
	std::cout << form3 << std::endl;
}
	std::cout << "###########################################" << std::endl;

	Form form1("High Form", 1, 1);
	std::cout << form1 << std::endl;

	test3.signForm(form1); // HIGH AND HIGH OK
	std::cout << form1 << std::endl;

	test3.signForm(form1); // Already Sign NOK
	std::cout << form1 << std::endl;

	Form form2("Another High Form", 1, 1);
	std::cout << form2 << std::endl;

	test2.signForm(form2); // LOW AND HIGH NOK
	std::cout << form2 << std::endl;

/* 
	try
	{
		form1.beSigned(test3);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << test3.getName() << " couldn’t sign " << form1.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeUnvailableException &e)
	{
		std::cerr << test3.getName() << " couldn’t sign " << form1.getName() << " because ";
	}
	catch (Form::SignStatusException &e)
	{
		std::cerr << test3.getName() << " couldn’t sign " << form1.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	 // Already Sign NOK
	std::cout << form1 << std::endl;
 */
	return (0);
}