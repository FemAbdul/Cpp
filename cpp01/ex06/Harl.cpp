#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout<<std::endl;
}

void Harl::info(void)
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout<<std::endl;
}

void Harl::warning(void)
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout<<std::endl;
}

void Harl::error(void)
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now.";
	std::cout<<std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] ={"DEBUG", "INFO", "WARNING", "ERROR"};
	func_ptr harl_ptrs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			switch (i)
			{
				case 0: (this->*harl_ptrs[0])();
						(this->*harl_ptrs[1])();
						(this->*harl_ptrs[2])();
						(this->*harl_ptrs[3])();
						break;
				case 1: (this->*harl_ptrs[1])();
						(this->*harl_ptrs[2])();
						(this->*harl_ptrs[3])();
						break;
				case 2: (this->*harl_ptrs[2])();
						(this->*harl_ptrs[3])();
						break;
				case 3: (this->*harl_ptrs[3])();
						break;
				default: break;
			}
			return ;
		}
		
	}
	std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
}
