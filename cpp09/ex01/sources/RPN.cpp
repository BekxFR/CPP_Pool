#include "RPN.hpp"

RPN::RPN() : _arg(""), _argStatus(0) {
	std::cout << "RPN Default Constructor called" << std::endl;
}

RPN::RPN(RPN const &obj) {
	*this = obj;
} ;

RPN::~RPN() {
	std::cout << "RPN Destructor called" << std::endl;
}

RPN &RPN::operator=(RPN const &obj) {
	std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->_stack = obj.getStack();
		this->_arg = obj.getArg();
		this->_argStatus = obj.getArgStatus();
	}
	return *this;
};

RPN::RPN(const std::string& arg) : _arg(arg), _argStatus(Parse_Reverse_Polish_Notation()) {
	std::cout << "RPN Overload Constructor called" << std::endl;
};


int	RPN::Parse_Reverse_Polish_Notation()
{
	std::string arg = this->getArg();
	std::cout << "ERERERERER = " << arg << std::endl;

	for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
		if (*it == ' ')
			continue;
		if (*it >= '0' && *it <= '9') {
			if (*(it + 1) == ' ' || (it + 1) == arg.end())
				continue;
			else
				return (1);
		} else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // || *it == '%') {
			if (*(it + 1) == ' ' || (it + 1) == arg.end())
				return (1);
		} else
			return (1);
	}
	return (0);
}


int	RPN::Reverse_Polish_Notation()
{
	int nbrOpe = 0;
	int nbr = 0;
	int nbr1 = 0;
	int nbr2 = 0;
	int res = 0;
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
		} else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // || *it == '%') {
			if (this->_stack.size() < 2) {
				std::cerr << "Error: not enough numbers to perform operation." << std::endl;
				return (1);
			}
			nbr1 = this->_stack.top();
			this->_stack.pop();
			nbr2 = this->_stack.top();
			this->_stack.pop();
			nbrOpe--;
			switch (*it) {
				case '+':
					res = nbr1 + nbr2;
					break;
				case '-':
					res = nbr2 - nbr1;
					break;
				case '*':
					res = nbr1 * nbr2;
					break;
				case '/':
					res = nbr2 / nbr1;
					break;
				// case '%':
				// 	res = nbr2 % nbr1;
				// 	break;
				default:
					break;
			}
			this->_stack.push(res);
		} else {
			std::cerr << "Error: bad input." << std::endl;
			return (1);
		}
	}
	if (nbrOpe == 0) {
		std::cerr << "Error: bad input." << std::endl;
		return (1);
	}
	if (nbrOpe > 1)
		std::cerr << "Error: too many operations." << std::endl;
	else
		std::cout << this->_stack.top() << std::endl;
	return (0);
}