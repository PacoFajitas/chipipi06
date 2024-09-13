/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:02:08 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/13 19:22:54 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& old)
{
	(void)old;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&old)
{
	(void)old;
	return *this;
}

void ScalarConverter::treat_special(std::string param, int aux)
{
	std::cout << "SOY ESPECIAAAAAAAAAAAAAAAAAAAAL" << std::endl;
	
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	if (!aux)
	{
		std::cout << "Float: " << param << "f"<< std::endl;
		std::cout << "Double: " << param << std::endl;		
	}
	else
	{
		std::cout << "Float: "<< param << std::endl;
		std::cout << "Double: " << param.substr(0, param.length()-1) << std::endl;
	}
		
	
}
void ScalarConverter::treat_double(std::string param)
{
	std::cout << "SOY DOOOOOOOOOOOOUBLEEEE" << std::endl;
	
	double dparam;
	
	dparam = strtod(param.c_str(), NULL);
	if(dparam >= 0 && dparam <= 127)
	{
		if (std::isprint(dparam))
			std::cout << "Char: '" << static_cast<char>(dparam) << "'" << std::endl;
		else
			std::cout << "Char: non displayable" << std::endl;
	}
	else
		std::cout << "Char: impossible" << std::endl;
	
	std::cout << "Int: '" << static_cast<int>(dparam) << "'" << std::endl;
	if(dparam == std::floor(dparam))
		std::cout << "Float: '" << static_cast<float>(dparam) << ".0f'" << std::endl;
	else
		std::cout << "Float: '" << static_cast<float>(dparam) << "f'" << std::endl;
	
	if(dparam == std::floor(dparam))
		std::cout << "Double: '" << dparam << ".0'" << std::endl;
	else
		std::cout << "Double: '" << dparam << "'" << std::endl;
}
void ScalarConverter::treat_float(std::string param)
{
	std::cout << "SOY FFFFFFFFFFFFFFFLOAAAAAAAAT" << std::endl;
	
	float fparam = strtof(param.c_str(), NULL);
	if(fparam >= 0 && fparam <= 127)
	{
		if (std::isprint(fparam))
			std::cout << "Char: '" << static_cast<char>(fparam) << "'" << std::endl;
		else
			std::cout << "Char: non displayable" << std::endl;
	}
	else
		std::cout << "Char: impossible" << std::endl;
	
	std::cout << "Int: '" << static_cast<int>(fparam) << "'" << std::endl;
	if(fparam == std::floor(fparam))
		std::cout << "Float: '" << fparam << ".0f'" << std::endl;
	else
		std::cout << "Float: '" << fparam << "f'" << std::endl;
	
	if(fparam == std::floor(fparam))
		std::cout << "Double: '" << static_cast<double>(fparam) << ".0'" << std::endl;
	else
		std::cout << "Double: '" << static_cast<double>(fparam) << "'" << std::endl;	
}
void ScalarConverter::treat_int(std::string param)
{
	std::cout << "SOY IIIIIIIIINT" << std::endl;
	
	int iparam = atoi(param.c_str());
	if(iparam >= 0 && iparam <= 127)
	{
		if (std::isprint(iparam))
			std::cout << "Char: '" << static_cast<char>(iparam) << "'" << std::endl;
		else
			std::cout << "Char: non displayable" << std::endl;
	}
	else
		std::cout << "Char: impossible" << std::endl;
	
	std::cout << "Int: '" << iparam << "'" << std::endl;
	std::cout << "Float: '" << static_cast<float>(iparam) << ".0f'" << std::endl;
	std::cout << "Double: '" << static_cast<double>(iparam) << ".0'" << std::endl;
}
void ScalarConverter::treat_char(std::string param)
{
	char c;
	
	std::cout << "SOY CHAAAAAAAAR" << std::endl;
	c = static_cast<char> (param.at(0));
	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: '" << static_cast<int>(c) << "'" << std::endl;
	std::cout << "Float: '" << static_cast<float>(c) << ".0f'" << std::endl;
	std::cout << "Double: '" << static_cast<double>(c) << ".0'" << std::endl;

	
}

static int ft_isnum(std::string param)
{
	int	ret;
	unsigned long i = 0;
	int point_counter = 0;
	
	ret = 1;
	while (i < param.length())
	{
		if (i == 0 && (param.at(0) == '-' || param.at(0) == '+'))
		{}
		else if (param.at(i) == '.')
			point_counter ++;
		else if (param.at(i) < '0' || param.at(i) > '9')
		{
			ret = 0;
			break;
		}
		i++;
	}
	if (ret == 0)
	{
		if(i > 1 && i == param.length()-1 && param.at(i) == 'f')
			ret = 1;
		else if (point_counter == 1)
			ret = 1;
		else
			ret = 0;
	}
	return ret;
}

void ScalarConverter::convert(std::string param)
{
	int is_num;
	
	is_num = ft_isnum(param);
	if (param.length() == 1 && !is_num)
	{
		treat_char(param);
	}
	else if(param.length() == 1 && is_num)
		treat_int(param);
	else if(is_num && param.find('f') == std::string::npos && param.find('.') == std::string::npos)
		treat_int(param);
	else if(is_num && param.find('f') == std::string::npos && param.find('.') != std::string::npos)
		treat_double(param);
	else if(is_num && param.find('f') != std::string::npos)
		treat_float(param);
	else if(!param.compare("-inf") || !param.compare("+inf")|| !param.compare("nan"))
		treat_special(param, 0);
	else if (!param.compare("+inff") || !param.compare("-inff") || !param.compare("nanf"))
		treat_special(param, 1);
		
}