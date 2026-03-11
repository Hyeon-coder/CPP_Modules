/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:48:43 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/12/20 07:33:07 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

std::string Contact::getNickname() const
{
	return this->_nickname;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}