/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:32:52 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/18 15:22:04 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Intern.hpp"
# include "../include/PresidentialPardonForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) {
	(void)other;
}
Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string	arr[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (int i = 0; i < 3; i++) {
		if (arr[i] == formName){
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0: return new PresidentialPardonForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new ShrubberyCreationForm(target);
			}
		}
	}
	std::cout << "Intern can not create " << formName << " that is available form name." << std::endl;
	return (NULL);
}
