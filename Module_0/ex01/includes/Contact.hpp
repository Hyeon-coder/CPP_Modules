/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:34:26 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/12/20 08:53:35 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

	std::string getFirstName() const;
	void	setFirstName(std::string str);
	std::string getLastName() const;
	void	setLastName(std::string str);
	std::string getNickname() const;
	void	setNickname(std::string str);
	std::string getPhoneNumber() const;
	void	setPhoneNumber(std::string str);
	std::string getDarkestSecret() const;
	void	setDarkestSecret(std::string str);
};

#endif