#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (target.size() < 1)
		_target = ("Undefined");
	std::cout << "ShrubberyCreationForm Overload Constructor called" << std::endl;
}

std::string const	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->execChecker(executor);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (GradeUnvailableException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (NoSignStatusException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	try
	{
		std::string stringOutfile = this->getTarget() + ("_shrubbery");
		const char *outfileName = &*stringOutfile.data();
		std::ofstream out_file(outfileName, std::ios::app);
		if (out_file.fail())
		{
			std::cout << "sorry, can't open " << stringOutfile << std::endl;
			return ; 
		}
		if (out_file.is_open())
		{
		std::string contents = 
"%%%%%%%%%%%%%%%%                                                                \n\
%%%%%%%%%%%%%%%%                                                                \n\
%%%%%%%                             #*##/*#                                     \n\
                               #####(/#/###*###                                 \n\
                             #(//#(////((*/((//#####                            \n\
                          ###%(((&&%(%&(/%/**/((##((#                           \n\
                         #((,(##(#(#/%%///&###(#/*/#((                          \n\
                        #//*///*/%&%(/(*%/%%%&#%(((/(*#                         \n\
                     //(%/%((@(/%&&/#%&&(%(*/&((%#/%/#%(                        \n\
                    (%(%&&&#((/%%(/##&&((//(&%(&%&#((%#((                       \n\
                   %%##(#%(&&%%#*///////&%/(#/#/%/*#*/*(//(                     \n\
                 ((#%(%%%//#@@&&@&#&%@&*%&%#%///(&&&(&/***//                    \n\
                #(%&((&&&%@&&@(&&(&&@@@&&&&&(&#%(/*#//&%%#(*/                   \n\
               (&&&%&((&%&#%%&&&(#&&&(((#%&#((%@#/&#####%#/(//                  \n\
               #&&&(%&@&&&&&&(@@&@@&&&@@&/##(%(/&(%#*(,(#%&**//                 \n\
               (#%%(&%%&%&&&&(((&@@@@@@&&@&&&%&%#/(%*#*(%(//((#/                \n\
               *&@%&&&&&@&&&#@&%@*%#&#(*(&@&&&%#&*%%&&##%(#%&#*##               \n\
               *&&%@@@@&&%&&#&&&&%&%%#%%&&@&#&&&#%&&&%&&&&/(#%%&                \n\
                %#&&&#/%@&&&&&&@@&&##&#@#&&%(@&&&&*/%&&%&%&%%%%                 \n\
                   (&&/#&%#&@&&@&&&&&@@#&/@&&&&&@&&%(*&*/%%*                    \n\
                            #(*(,,,*@@@(,&&&#(&&%*,,%,%*                        \n\
                                    *@@*@@*                                     \n\
    .            .      .           @@*@@&@      .           .                  \n\
/***//*///(//*/***/*//*((/////*////*//*((////////((////(/(////*/(*/(////*///***/\n\
*/.*,*****,.****/*(/,//***,**/(,**/*,/*//*/////,*****(/*/*/***(//*////////,/////\n\
**,*,**,,* //,/*/,(,**.*******/*/*/**/,*****./*/,/./.*,*.***/******/*,*,*,*,/**/\n\
/**/*/*.***/,/*/*/*/,/, */*/***///*,/*(///***/***//,///*//*(/,/,/(/////*,,*,,/**\n\
//*/*//,/(*,,,*.*/*. //,,**//,*/.,.,/*..#*.*/,**/*//.***(/***//*/****//,/*,//*.*\n\
/.,./*/(,*/*.*/,****,//**,*,,.*/*,,,/***////(*,//,***/,(,//.**,********/*/////(*\n\n";
		out_file << contents;
		}
	}
	catch(const std::exception &exc)
	{
		std::cerr << "Error 1 : " << std::strerror(errno) << std::endl;
	}
}
