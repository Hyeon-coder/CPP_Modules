/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:49:45 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/12/21 19:51:39 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_is_armed = false;
	std::cout << this->_name <<" joined" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " died." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_is_armed = true;
	std::cout << this->_name << " grabbed a " << this->_weapon->getType() << " to fight with." << std::endl;
}

void HumanB::attack(void)
{
    if (this->_is_armed)
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << "." << std::endl;
    else
        std::cout << this->_name << " attacks with his sword." << std::endl;
}
