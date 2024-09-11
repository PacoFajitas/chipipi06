/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:02:08 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/11 19:00:57 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


static void treat_special(std::string param){}
static void treat_double(std::string param){}
static void treat_float(std::string param){}
static void treat_int(std::string param)
{}
static void treat_char(std::string param)
{
	param
}

static int ft_isnum(std::string param)
{
	int	ret;
	int i = 0;
	int point_counter = 0;
	
	ret = 0;
	while ( i < param.length())
	{
		if (i == 0 && (param.at(0) == '-' || param.at(0) == '+'))
			i = 0;
		else if (param.at(i) == '.')
			point_counter ++;
		else if (param.at(i) < '0' || param.at(i) > '9')
		{
			ret = 0;
			break;
		}
		i++;
	}
	if(i == param.length() && param.at(i - 1) == 'f')
		ret = 0;
	else if(point_counter <= 1) // el punto tiene que tener numeros detras
		ret = 0;
	else
		ret = 1;
	return ret;
}

void ScalarConverter::convert(std::string param)
{
	
	if (param.length() == 1 && !ft_isnum(param))
		treat_char(param);
	else if(param.length() == 1 && ft_isnum(param))
		treat_int(param);
	else if(ft_isnum(param) && param.find('f') == std::string::npos && param.find('.') == std::string::npos)
		treat_int(param);
	else if(ft_isnum(param) && param.find('f') == std::string::npos && param.find('.') != std::string::npos)
		treat_double(param);
	else if(ft_isnum(param) && param.find('f') != std::string::npos && param.find('.') == std::string::npos)
		treat_float(param);
	else if(!param.compare("-inff") || !param.compare("+inff") || !param.compare("-inf") || !param.compare("+inf")
			|| !param.compare("nan"))
			treat_special(param);
		
}