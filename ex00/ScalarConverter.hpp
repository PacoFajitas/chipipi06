/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:02:10 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/13 19:20:16 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
	public:
		static void convert(std::string param);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &old);
		ScalarConverter& operator=(const ScalarConverter& old);
		~ScalarConverter();
		static void treat_special(std::string param, int aux);
		static void treat_double(std::string param);
		static void treat_float(std::string param);
		static void treat_int(std::string param);
		static void treat_char(std::string param);
};

#endif