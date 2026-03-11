/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:16:36 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/08 22:38:34 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
	Shallow copy only copies pointer address. both objects share the same memory.
	Deep copy creates a new memory and copy.
	So, If change the value or delete then Shallow will affect both,
	but Deep will affect only the tried one.
*/

int main()
{
	std::cout << "===== Array of Animals Test =====" << std::endl;
	int size = 4;
	Animal* animals[size];
	std::cout << "------- constructor called -------"<< std::endl;
	for (int k = 0; k < size; k++)
	{
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	std::cout << "------- destructor called -------"<< std::endl;
	for (int k = 0; k < size; k++)
		delete animals[k];
	std::cout << "\n===== Deep Copy Test =====" << std::endl;
	std::cout << "------- constructor called -------"<< std::endl;
	Dog basic;
	{
		std::cout << "\n------- copy constructor called -------"<< std::endl;
		Dog tmp = basic;
		std::cout << "\n------- destructor called -------"<< std::endl;
	}
	std::cout << "\n===== Assignment Operator Test =====" << std::endl;
	std::cout << "------- constructor called -------"<< std::endl;
	Dog dog1;
	Dog dog2;
	std::cout << "\n------- copy assignment operator called -------"<< std::endl;
	dog2 = dog1;
	std::cout << "\n------- destructor called -------"<< std::endl;
	return 0;
}