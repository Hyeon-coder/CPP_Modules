/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

// TODO: Orthodox Canonical Form 구현
// - 생성자, 소멸자, 복사 생성자, 대입 연산자

// TODO: serialize 구현
// 힌트: 포인터 → uintptr_t 변환에 어떤 cast를 써야 할까?

// TODO: deserialize 구현
// 힌트: uintptr_t → 포인터 변환에 어떤 cast를 써야 할까?

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer&) {}

Serializer& Serializer::operator=(const Serializer&) {
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data			*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}