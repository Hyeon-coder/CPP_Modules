/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:29:36 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/01/13 04:58:41 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fixedValue;
	static const int	_fractionBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);				// copy constructor(복사 생성자)
	Fixed& operator=(const Fixed& other);	// copy Assignment Operator(복사 대입 연산자)
	~Fixed();

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif