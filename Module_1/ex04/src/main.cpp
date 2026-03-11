/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <JuHyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:21:14 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/12/23 04:04:34 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceAll(std::string& line, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return;
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

// File will close automatically but what if program is complecate then, 
// If you no longer need the file, it recommend closeing it.

// File open is inside constructor of ifstream.
// And c_str is just for trans to (char *). It's need for C++98 can take only string of C style
// and can't take C++ style(std::string)
bool processFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (false);
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << outputFilename << std::endl;
		// inputFile.close();
		return (false);
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		replaceAll(line, s1, s2);
		outputFile << line << std::endl;
	}
	// inputFile.close();
	// outputFile.close();
	std::cout << "complete. saved >> " << outputFilename << std::endl;
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid arguments." << std::endl;
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (!processFile(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}
