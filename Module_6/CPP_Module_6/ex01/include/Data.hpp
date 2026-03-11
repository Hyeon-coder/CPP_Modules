/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/03/09 00:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

// TODO: Data 구조체를 정의하세요
// - 비어있으면 안 됨 (데이터 멤버가 있어야 함)
// - 예: int id, std::string name 등

struct Data {
	int			id;
	std::string	name;
	// uintptr_t	*ptr;
};

#endif
