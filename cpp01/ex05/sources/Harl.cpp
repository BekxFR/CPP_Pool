#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::complain(std::string level)
{
	// std::string ftab[4];
	// ftab[0] = "DEBUG";
	// ftab[1] = "INFO";
	// ftab[2] = "WARNING";
	// ftab[3] = "ERROR";
	std::string ftab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])();
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	// void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int n = 0; n < 4; n++)
	{
		if (ftab[n] == level)
		{
			(this->*f[n])();
			return ;
		}
	}
	std::cout << "I think this job is not for you! Stop distrubing me for nothing. I eating my bacon!" << std::endl;
	return ;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}
void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
