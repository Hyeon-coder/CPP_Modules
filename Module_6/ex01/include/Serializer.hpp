/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

// TODO: Serializer 클래스를 완성하세요
// - 사용자가 인스턴스화할 수 없어야 함 (ex00의 ScalarConverter 패턴 참고)
// - 두 개의 public static 메서드:
//   1) uintptr_t serialize(Data* ptr);
//   2) Data* deserialize(uintptr_t raw);

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
