/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:31:51 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/13 20:29:56 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <iomanip>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e( 123.456789f );
	a = Fixed( 1234.4321f );
	std::cout << "before setprecision" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << std::setprecision(12);
	std::cout << "after setprecision" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

// #include <iomanip>
// int main() {
//     float originalValue = 1.003f; // 사용자가 입력한 실수
//     int fractionBits = 8;
//     int scale = 1 << fractionBits; // 2^8 = 256

//     std::cout << "--- 고정 소수점 변환 시뮬레이션 (원본: " << originalValue << ") ---" << std::endl;

//     // 1단계: 실수에 256을 곱함
//     float scaledValue = originalValue * scale; 
//     std::cout << "1. 256을 곱한 값: " << scaledValue << std::endl; // 256.768

//     // 2단계: 저장 방식 비교
//     // [방법 A] roundf 사용 (현재 질문자님의 코드 방식)
//     int withRound = (int)roundf(scaledValue); 
    
//     // [방법 B] 단순 캐스팅 (버림 현상 발생)
//     int withoutRound = (int)scaledValue;

//     std::cout << "\n2. 내부 저장 값 (int _fixedValue) 비교:" << std::endl;
//     std::cout << "   - [roundf 사용]: " << withRound << " (256.768을 반올림)" << std::endl;
//     std::cout << "   - [단순 버림  ]: " << withoutRound << " (256.768에서 .768을 삭제)" << std::endl;

//     // 3단계: 다시 float으로 복원 (toFloat 함수 로직)
//     float restoredWithRound = (float)withRound / scale;
//     float restoredWithoutRound = (float)withoutRound / scale;

//     std::cout << "\n3. 최종 복원된 값 (toFloat):" << std::endl;
//     std::cout << std::fixed << std::setprecision(8);
//     std::cout << "   - [roundf 사용 결과]: " << restoredWithRound << std::endl;    // 1.00390625
//     std::cout << "   - [단순 버림 결과  ]: " << restoredWithoutRound << std::endl; // 1.00000000

//     // 4단계: 오차 분석
//     std::cout << "\n4. 원본(1.003)과의 오차:" << std::endl;
//     std::cout << "   - [roundf 오차]: " << std::abs(originalValue - restoredWithRound) << std::endl;
//     std::cout << "   - [단순 버림 오차]: " << std::abs(originalValue - restoredWithoutRound) << std::endl;

//     return 0;
// }