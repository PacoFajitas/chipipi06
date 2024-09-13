/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:16:39 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/14 00:19:30 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int	main()
{
	Base detec;
	Base* sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(*sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	return 0;
}