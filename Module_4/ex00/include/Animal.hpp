/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:52:33 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/05 15:12:17 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

/*
	~Animal() will upcasting(Animal* pointer pointing to Dog or Cat) and call the child class's destructor.
	that is why in the result, Dog and Cat's destructor is called first, then Animal's destructor is called.
*/

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif