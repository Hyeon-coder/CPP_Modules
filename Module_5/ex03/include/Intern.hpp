/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:22:19 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/18 14:37:06 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class	Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);

		AForm* makeForm(std::string formName, std::string target);

		class noFormName : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif