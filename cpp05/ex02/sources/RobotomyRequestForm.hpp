/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:13:44 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:13:45 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "PresidentialPardonForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);

		std::string const	getTarget() const;

		void	execute(Bureaucrat const &executor) const;
};

#endif
