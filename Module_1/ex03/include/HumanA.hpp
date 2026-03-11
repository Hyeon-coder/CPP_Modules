/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:34:13 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/12/21 06:52:55 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
	A 는 시작부터 무기를 갖는다.
	포인터로 생성 한다면 사용자가 무기를 주지 않았을 때 SegFault 가 나올 수 있다.
	또한 NULL 체크를 생략 할 수 있어서 코드가 간결 하다.
	참조자 로 생성 할 때는 무기가 들어가지 않는다면 코드 자체가 성립이 되지 않는다.
	따라서, 시스템 적 으로 사용자 의 실수를 막을 수 있다.
*/

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
		
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};

#endif
