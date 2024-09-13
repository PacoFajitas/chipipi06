/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero < tfiguero@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:24:07 by tfiguero          #+#    #+#             */
/*   Updated: 2024/09/13 21:53:47 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


	Serializer::Serializer(){}
	Serializer::Serializer(const Serializer& old){(void)old;}
	Serializer& Serializer::operator=(const Serializer& old)
	{
		(void)old;
		return *this;
	}
	Serializer::~Serializer(){}
	
	uintptr_t Serializer::serialize(Data *ptr)
	{
		return reinterpret_cast<uintptr_t>(ptr);
	}
	
	Data* Serializer::deserialize(uintptr_t raw)
	{
		return reinterpret_cast<Data*>(raw);
	}