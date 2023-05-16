#include "RPN.hpp"

RPN::RPN() : _stack(), _arg(""), _argStatus(0) {
	if (DEBUG == 1)
		std::cout << "RPN Default Constructor called" << std::endl;
}

RPN::RPN(RPN const &obj) {
	*this = obj;
}

RPN::~RPN() {
	if (DEBUG == 1)
		std::cout << "RPN Destructor called" << std::endl;
}

RPN &RPN::operator=(RPN const &obj) {
	if (DEBUG == 1)
		std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_stack = obj.getStack();
		this->_arg = obj.getArg();
		this->_argStatus = obj.getArgStatus();
	}
	return *this;
};

RPN::RPN(const std::string& arg) : _stack(), _arg(arg), _argStatus(Parse_Reverse_Polish_Notation()) {
	if (DEBUG == 1)
		std::cout << "RPN Overload Constructor called" << std::endl;
};

bool	RPN::Parse_Reverse_Polish_Notation()
{
	std::string arg = this->getArg();

	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
		if (*it == ' ')
			continue;
		if (*it >= '0' && *it <= '9') {
			if (*(it + 1) != ' ' && (it + 1) != arg.end())
				return (false);
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // || *it == '%') {
			if (*(it + 1) != ' ' && (it + 1) != arg.end())
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

int	RPN::Reverse_Polish_Notation()
{
	long int nbrOpe = 0;
	long int nbr = 0;
	long int nbr1 = 0;
	long int nbr2 = 0;
	long int res = 0;
	std::string arg = this->getArg();

	for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it) {
		if (*it == ' ')
			continue;
		if (*it >= '0' && *it <= '9') {
			nbr = nbr * 10 + *it - '0';
			if (*(it + 1) == ' ' || (it + 1) == arg.end()) {
				this->_stack.push(nbr);
				nbr = 0;
				nbrOpe++;
			}
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // || *it == '%') {
			if (this->_stack.size() < 2) {
				std::cout << "Error: not enough numbers to perform operation." << std::endl;
				return (1);
			}
			nbr1 = this->_stack.top();
			this->_stack.pop();
			nbr2 = this->_stack.top();
			this->_stack.pop();
			nbrOpe--;
			switch (*it) {
				case '+':
					res = nbr2 + nbr1;
					break;
				case '-':
					res = nbr2 - nbr1;
					break;
				case '*':
					res = nbr2 * nbr1;
					break;
				case '/':
					if (nbr1 == 0) {
						std::cout << "Error: Divide by zero." << std::endl;
						return (1);
					}
					res = nbr2 / nbr1;
					break;
				// case '%':
				// 	if (nbr1 == 0) {
				// 		std::cout << "Error: Modulo by zero." << std::endl;
				// 		return (1);
				// 	}
				// 	res = nbr2 % nbr1;
				// 	break;
				default:
					break;
			}
			this->_stack.push(res);
		}
		else {
			std::cout << "Error: bad input." << std::endl;
			return (1);
		}
	}
	if (nbrOpe == 0) {
		std::cout << "Error: bad input." << std::endl;
		return (1);
	}
	if (nbrOpe > 1)
		std::cout << "Error: too many operations." << std::endl;
	else
		std::cout << this->_stack.top() << std::endl;
	return (0);
}