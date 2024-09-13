/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:02 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/14 00:24:35 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{
	std::cout << "Destuctor called for base" << std::endl;
}
Base * Base::generate(void)
{
	int i = rand() % 3 + 1;

	std::cout << i << std::endl;
	if (i == 1)
	{
		std::cout << "Gen: Its A" << std::endl;
		return new A;
	}
	else if (i == 2)
	{
		std::cout << "Gen: Its B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Gen: Its C" << std::endl;
		return new C;
	}
}

void Base::identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	
	if(a)
		std::cout << "The object is from type A" << std::endl;
	if(b)
		std::cout << "The object is from type B" << std::endl;
	if(c)
		std::cout << "The object is from type C" << std::endl;
}
void Base::identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		
		std::cout << "The object is from type A" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
	try
	{
		B a = dynamic_cast<B &>(p);
		
		std::cout << "The object is from type B" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
	try
	{
		C a = dynamic_cast<C &>(p);
		
		std::cout << "The object is from type C" << std::endl;
	}
	catch(const std::exception& e)
	{
		
	}
	
}