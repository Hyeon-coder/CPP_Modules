/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "../include/A.hpp"
# include "../include/B.hpp"
# include "../include/C.hpp"

// TODO: 아래 세 함수를 구현하세요

// Base* generate(void);
// - A, B, C 중 하나를 랜덤으로 생성하여 Base* 로 반환
// - 힌트: std::rand() 또는 std::srand(std::time(NULL)) + rand() % 3

// void identify(Base* p);
// - p가 실제로 A인지, B인지, C인지 출력
// - 힌트: dynamic_cast<A*>(p) 가 NULL이 아니면 A

// void identify(Base& p);
// - 레퍼런스 버전. 포인터 사용 금지!
// - 힌트: dynamic_cast<A&>(p) 가 실패하면 std::exception 을 throw 함
//   → try/catch 로 잡아야 함

int	main(void)
{
	// TODO: 테스트 코드
	// 1. generate()로 랜덤 객체 생성
	// 2. identify(Base* p) 로 타입 확인
	// 3. identify(Base& p) 로 타입 확인
	// 4. delete 잊지 말기

	return (0);
}
