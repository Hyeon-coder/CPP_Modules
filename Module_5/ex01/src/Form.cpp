/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:32:58 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/14 17:43:12 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (1 <= grade <= 150)");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (1 <= grade <= 150)");
}

Form::Form()
	: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gts, int gte)
	: _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned)
		, _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "\n\t    name : " << f.getName() << std::endl;
	os << "\t  status : " << (f.getIsSigned() ? "signed" : "not signed") << std::endl;
	os << "   grade to sign : " << f.getGradeToSign() << std::endl;
	os << "grade to execute : " << f.getGradeToExecute() << std::endl;
	return os;
}