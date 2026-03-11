/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:03:43 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/18 15:22:47 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
	Intern	someRandomIntern;
	AForm*	rra;
	AForm*	rrb;
	AForm*	rrc;

	rra = someRandomIntern.makeForm("presidential pardon", "Bender");
	rrb = someRandomIntern.makeForm("robotomy request", "Bender");
	rrc = someRandomIntern.makeForm("shrubbery creation", "Bender");
	
	return (0);
}