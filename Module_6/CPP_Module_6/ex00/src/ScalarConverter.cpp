/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:50:44 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/03/08 19:10:52 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return (*this);
}

static bool	isPseudo(const std::string& str) {
	return (str == "nan" || str == "nanf" ||
		str == "+inf" || str == "-inf" ||
		str == "+inff" || str == "-inff");
}

static bool	isChar(const std::string& str) {
	return (str.length() == 3 &&
			str[0] == '\'' &&
			str[2] == '\'');
}

static bool	isInt(const std::string& str) {
	int	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start == (int)str.length())
		return (false);
	for (int i = start; i < (int)str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool	isFloat(const std::string& str) {
	if (str[str.length() - 1] != 'f')
		return (false);
	std::string withoutF = str.substr(0, str.length() - 1);
	if (withoutF.find('.') == std::string::npos)
		return (false);
	int	start = 0;
	if (withoutF[0] == '+' || withoutF[0] == '-')
		start = 1;
	int	dotCnt = 0;
	for (int i = start; i < (int)withoutF.length(); i++) {
		if (withoutF[i] == '.')
			dotCnt++;
		else if (!std::isdigit(withoutF[i]))
			return (false);
	}
	return (dotCnt == 1);
}

static bool	isDouble(const std::string& str) {
	if (str.find('.') == std::string::npos)
		return (false);
	int	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	int	dotCnt = 0;
	for (int i = start; i < (int)str.length(); i++) {
		if (str[i] == '.')
			dotCnt++;
		else if (!std::isdigit(str[i]))
			return (false);
	}
	return (dotCnt == 1);
}

static int	toInt(const std::string& str) {
	int	rst;
	std::istringstream(str) >> rst;
	return (rst);
}

static float	toFloat(const std::string& str) {
	float	rst;
	std::istringstream(str) >> rst;
	return (rst);
}

static double	toDouble(const std::string& str) {
	double	rst;
	std::istringstream(str) >> rst;
	return (rst);
}

static void	printAll(double d) {
	// print char
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	// print int
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	// print float
	float	f = static_cast<float>(d);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" <<std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	// print double
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+" : "-") << "inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::convert(const std::string& literal) {
	if (isPseudo(literal)) {
		double d;
		if (literal == "nan" || literal == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "+inff")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
		printAll(d);
	}
	else if (isChar(literal))
		printAll(static_cast<double>(literal[1]));
	else if (isInt(literal))
		printAll(static_cast<double>(toInt(literal)));
	else if (isFloat(literal))
		printAll(static_cast<double>(toFloat(literal)));
	else if (isDouble(literal))
		printAll(toDouble(literal));
	else
		std::cout << "Error: invalid literal" << std::endl;
}