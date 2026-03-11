/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:03:43 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/16 10:23:24 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Arthur Dent");

        // 1. 등급 부족 테스트
        intern.executeForm(f1); 

        // 2. 서명 안 된 서류 실행 테스트
        boss.executeForm(f1);

        // 3. 정상 실행 테스트
        boss.signForm(f1);
        boss.executeForm(f1);

        boss.signForm(f2);
        boss.executeForm(f2); // 50% 확률 확인

        boss.signForm(f3);
        boss.executeForm(f3);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}