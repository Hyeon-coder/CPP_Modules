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
# include "Serializer.hpp"

int	main(void)
{
	Data data;
	data.id = 42;
	data.name = "test";

	std::cout << "=== Original ===" << std::endl;
	std::cout << "Address: " << &data << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "name: " << data.name << std::endl;

	// serialize: pointer → uintptr_t
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "raw: " << raw << std::endl;

	// deserialize: uintptr_t → pointer
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "\n=== Deserialized ===" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "name: " << ptr->name << std::endl;

	std::cout << "\n=== Compare ===" << std::endl;
	if (ptr == &data)
		std::cout << "Ok: pointers match" << std::endl;
	else
		std::cout << "Ko: pointers different" << std::endl;

	return (0);
}
