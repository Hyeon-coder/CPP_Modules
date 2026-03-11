/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:43:44 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/12/20 08:29:23 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_count = 0;
}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_truncate(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

bool    PhoneBook::_getInput(std::string prompt,
                            std::string &output,
                            bool numericOnly) const
{
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, output))
            return (false);
        if (output.empty())
        {
            std::cout << "Field cannot be empty." << std::endl;
            continue ;
        }
        if (numericOnly) 
        {
            bool    valid = true;
            for (size_t i = 0; i < output.length(); i++)
            {
                if (!std::isdigit(output[i]))
                {
                    valid = false;
                    break ;
                }
            }
            if (!valid)
            {
                std::cout << "Phone number must contain only digits." << std::endl;
                continue ;
            }
        }
        return (true);
    }
}

bool    PhoneBook::add()
{
    std::string input;
    Contact     &newContact = this->_contacts[this->_index % 8];

    if (!_getInput("First Name: ", input))
        return (false);
    newContact.setFirstName(input);
    if (!_getInput("Last Name: ", input))
        return (false);
    newContact.setLastName(input);
    if (!_getInput("Nickname: ", input))
        return (false);
    newContact.setNickname(input);
    if (!_getInput("Phone Number: ", input, true))
        return (false);
    newContact.setPhoneNumber(input);
    if (!_getInput("Darkest Secret: ", input))
        return (false);
    newContact.setDarkestSecret(input);
    this->_index++;
    if (this->_count < 8)
        this->_count++;
    std::cout << "Successfully added!" << std::endl;
    return (true);
}

bool    PhoneBook::search()
{
    if (this->_count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return (true);
    }
    std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name"
                << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
    for(int i = 0; i < this->_count; i++)
    {
        std::cout << "|" << std::setw(10) << (i + 1) << "|";
        std::cout << std::setw(10) << _truncate(this->_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << _truncate(this->_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << _truncate(this->_contacts[i].getNickname()) << "|" << std::endl;
    }
    std::string input;
    if (!_getInput("Enter index to display: ", input))
        return (false);
    if (input.length() == 1 && input[0] >= '1' && input[0] <= '0' + this->_count)
    {
        int idx = input[0] - '1';
        std::cout << "First Name: " << this->_contacts[idx].getFirstName() << std::endl;
        std::cout << "Last Name: " << this->_contacts[idx].getLastName() << std::endl;
        std::cout << "Nickname: " << this->_contacts[idx].getNickname() << std::endl;
        std::cout << "Phone Number: " << this->_contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secreat: " << this->_contacts[idx].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
    return (true);
}