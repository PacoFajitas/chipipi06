/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:02:20 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/13 17:54:40 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("-4.f");
	ScalarConverter::convert("-4.");
	ScalarConverter::convert("-40000");
	ScalarConverter::convert("*");
	ScalarConverter::convert("-inff");
}