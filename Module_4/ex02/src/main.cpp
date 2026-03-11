/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:58:52 by JuHyeon           #+#    #+#             */
/*   Updated: 2026/01/08 22:38:40 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
	If parent class is abstract class, 
	child class must override pure virtual function.
	if not, child class also will be abstract class.
*/

int main()
{
	// Animal test;
	/*
		Animal class is Abstract Class it has pure virtual function.
		So, we cannot instantiate an object of Animal class.
	*/
	std::cout << "===== Array of Animals Test =====" << std::endl;
	int size = 4;
	Animal* animals[size];
	std::cout << "------- constructor called -------" << std::endl;
	for (int k = 0; k < size; k++)
	{
		if (k < size / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	std::cout << "\n------- makeSound called -------" << std::endl;
	for (int k = 0; k < size; k++)
		animals[k]->makeSound();
	std::cout << "\n------- destructor called -------" << std::endl;
	for (int k = 0; k < size; k++)
		delete animals[k];
	std::cout << "\n===== Deep Copy Test =====" << std::endl;
	std::cout << "------- constructor called -------" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "\n------- makeSound called -------" << std::endl;
		tmp.makeSound();
		std::cout << "\n------- destructor called -------" << std::endl;
	}
	std::cout << "\n===== Assignment Operator Test =====" << std::endl;\
	std::cout << "------- constructor called -------" << std::endl;
	Dog dog1;
	Dog dog2;
	std::cout << "\n------- assignment operator called -------" << std::endl;
	dog2 = dog1;
	std::cout << "\n------- makeSound called -------" << std::endl;
	dog2.makeSound();
	std::cout << "\n------- destructor called -------" << std::endl;
	return 0;
}