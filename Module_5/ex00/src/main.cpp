/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:03:43 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/12 00:14:14 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- normal test ---" << std::endl;
	try {
		Bureaucrat alpha("alpha", 2);
		std::cout << alpha << std::endl;
		alpha.incrementGrade();		// 2 -> 1
		std::cout << "After increment: " << alpha << std::endl;
		alpha.decrementGrade();		// 1 -> 2
		std::cout << "after decrement: " << alpha << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too High (constructor) ---" << std::endl;
	try {
		Bureaucrat beta("beta", 0);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too Low (constructor) ---" << std::endl;
	try {
		Bureaucrat charlie("charlie", 151);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too High (function) ---" << std::endl;
	try {
		Bureaucrat delta("delta", 1);
		std::cout << delta << std::endl;
		delta.incrementGrade();		// 1 -> 0
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too Low (function) ---" << std::endl;
	try {
		Bureaucrat echo("echo", 150);
		std::cout << echo << std::endl;
		echo.decrementGrade();		// 150 -> 151
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}