/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:27:11 by juhyeonl          #+#    #+#             */
/*   Updated: 2026/02/18 15:22:22 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkExecutable(executor);
	std::string	filename = _target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Could not open file");
	outfile << " ###########################'`################################" << std::endl;
	outfile << " ###########################  V##'############################" << std::endl;
	outfile << " #########################V'  `V  ############################" << std::endl;
	outfile << " ########################V'      ,############################" << std::endl;
	outfile << " #########`#############V      ,A###########################V" << std::endl;
	outfile << " ########' `###########V      ,###########################V',#" << std::endl;
	outfile << " ######V'   ###########l      ,####################V~~~~'',###" << std::endl;
	outfile << " #####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl;
	outfile << " #####l      d#########l      V'  ,#######V~'       A#########" << std::endl;
	outfile << " #####l      ##########l         ,####V''         ,###########" << std::endl;
	outfile << " #####l        `V######l        ,###V'   .....;A##############" << std::endl;
	outfile << " #####A,         `######A,     ,##V' ,A#######################" << std::endl;
	outfile << " #######A,        `######A,    #V'  A########'''''##########''" << std::endl;
	outfile << " ##########,,,       `####A,           `#''           '''  ,,," << std::endl;
	outfile << " #############A,                               ,,,     ,######" << std::endl;
	outfile << " ######################oooo,                 ;####, ,#########" << std::endl;
	outfile << " ##################P'                   A,   ;#####V##########" << std::endl;
	outfile << " #####P'    ''''       ,###             `#,     `V############" << std::endl;
	outfile << " ##P'                ,d###;              ##,       `V#########" << std::endl;
	outfile << " ##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl;
	outfile << " #############A, Y#########A,            )####, ,#############" << std::endl;
	outfile << " ###############A ############A,        ,###### ##############" << std::endl;
	outfile << " ###############################       ,#######V##############" << std::endl;
	outfile << " ###############################      ,#######################" << std::endl;
	outfile << " ##############################P    ,d########################" << std::endl;
	outfile << " ##############################'    d#########################" << std::endl;
	outfile << " ##############################     ##########################" << std::endl;
	outfile << " ##############################     ##########################" << std::endl;
	outfile << " #############################P     ##########################" << std::endl;
	outfile << " #############################'     ##########################" << std::endl;
	outfile << " ############################P      ##########################" << std::endl;
	outfile << " ###########################P'     ;##########################" << std::endl;
	outfile << " ###########################'     ,###########################" << std::endl;
	outfile << " ##########################       ############################" << std::endl;
	outfile << " #########################       ,############################" << std::endl;
	outfile << " ########################        d###########P'    `Y#########" << std::endl;
	outfile << " #######################        ,############        #########" << std::endl;
	outfile << " ######################        ,#############        #########" << std::endl;
	outfile << " #####################        ,##############b.    ,d#########" << std::endl;
	outfile << " ####################        ,################################" << std::endl;
	outfile << " ###################         #################################" << std::endl;
	outfile << " ##################          #######################P'  `V##P'" << std::endl;
	outfile << " #######P'     `V#           ###################P'" << std::endl;
	outfile << " #####P'                    ,#################P'" << std::endl;
	outfile << " ###P'                      d##############P''" << std::endl;
	outfile << " ##P'                       V##############'" << std::endl;
	outfile << " #P'                         `V###########'" << std::endl;
	outfile << " #'                             `V##P'" << std::endl;
	outfile.close();
}

