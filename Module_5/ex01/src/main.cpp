/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:03:43 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/12 01:45:42 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	try {
		Bureaucrat	alpha("alpha", 1);
		Bureaucrat	beta("beta", 150);

		Form		highForm("highForm", 10, 1);
		Form		highForm_forfailure("highForm_forfailure", 10, 1);
		Form		lowForm("lowForm", 150, 150);

		std::cout << "-------------- state --------------" << std::endl;
		std::cout << highForm << std::endl;
		std::cout << lowForm << std::endl;

		std::cout << "-------------- sign success --------------" << std::endl;
		alpha.signForm(highForm);
		std::cout << highForm << std::endl;

		std::cout << "-------------- sign failure --------------" << std::endl;
		beta.signForm(highForm_forfailure);
		std::cout << highForm_forfailure << std::endl;

		std::cout << "-------------- exception test --------------" << std::endl;
		Form exceptForm("except", 0, 151);
	} catch (std::exception& e) {
		std::cerr << "Exeception: " << e.what() << std::endl;
	}
}