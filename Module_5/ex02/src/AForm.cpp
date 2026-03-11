/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:32:58 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/16 10:28:02 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (1 <= grade <= 150)");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (1 <= grade <= 150)");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

AForm::AForm()
	: _name("default")
	, _isSigned(false)
	, _gradeToSign(150)
	, _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gts, int gte)
	: _name(name), _isSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _gradeToSign(other._gradeToSign)
	, _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::checkExecutable(Bureaucrat const & executor) const 
{
	if (!_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "\n\t    name : " << f.getName() << std::endl;
	os << "\t  status : " << (f.getIsSigned() ? "signed" : "not signed") << std::endl;
	os << "   grade to sign : " << f.getGradeToSign() << std::endl;
	os << "grade to execute : " << f.getGradeToExecute() << std::endl;
	return os;
}