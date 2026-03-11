/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:16:36 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/27 14:47:30 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
	in Animal class is a virtual function
	so we cannot create an instance of Animal class directly. it is Dynamic Binding.
	But in WrongAnimal class is not a virtual function
	so we can create an instance of WrongAnimal class directly. it is Static Binding.
	Dynamic Binding can use makeSound() function of child class
	but Static Binding cannot use makeSound() function of child class.
*/
int main()
{
	std::cout << "======== Constructor ========" << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "\n======== Type ========" << std::endl;
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << "\n======== Sound ========" << std::endl;
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	std::cout << "\n======== Destructor ========" << std::endl;
	delete(cat);
	delete(dog);
	delete(animal);
	std::cout << "\n======== WRONG ========" << std::endl;
	std::cout << "======== Constructor ========" << std::endl;
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << "\n======== Type ========" << std::endl;
	std::cout << wronganimal->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	std::cout << "\n======== Sound ========" << std::endl;
	wronganimal->makeSound();
	wrongcat->makeSound();
	std::cout << "\n======== Destructor ========" << std::endl;
	delete(wrongcat);
	delete(wronganimal);
	return 0;
}