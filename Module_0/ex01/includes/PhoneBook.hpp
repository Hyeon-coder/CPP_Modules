/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:02:01 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/12/20 08:42:56 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_index;
	int		_count;

	std::string	_truncate(std::string str) const;
	bool		_getInput(std::string prompt, std::string &output, bool numericOnly = false) const;

public:
	PhoneBook();
	~PhoneBook();

	bool	add();
	bool	search();
};

#endif