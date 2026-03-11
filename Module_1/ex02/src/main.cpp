/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:10:39 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/10/09 14:20:15 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	const std::string string = "HI THIS IS BRAIN";
	const std::string* stringPTR = &string;
	const std::string& stringREF = string;

	std::cout << "address of the string variable >> " << &string << std::endl;
	std::cout << "address held by stringPTR >> " << stringPTR <<std::endl;
	std::cout << "address held by stringREF >> " << &stringREF << std::endl;
	
	std::cout << "value of the string variable >> " << string << std::endl;
	std::cout << "value pointed to by stringPTR >> " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF >> " << stringREF << std::endl;
	
	return (0);
}
