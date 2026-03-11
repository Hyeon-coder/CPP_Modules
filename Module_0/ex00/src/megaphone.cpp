/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:41:59 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/12/05 17:25:09 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j] != '\0'; ++j)
			{
				char c = argv[i][j];
				if (c >= 'a' && c <= 'z')
					std::cout << (char)(c - 32);
				else
					std::cout << c;
			}
			if (i < argc - 1)
			   std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}
