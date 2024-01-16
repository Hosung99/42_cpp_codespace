/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:57:25 by seoson            #+#    #+#             */
/*   Updated: 2024/01/16 23:14:51 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data		data;
	Data*		data2;
	data.member = 1;
	data2 = Serialization::deserialize(Serialization::serialize(&data));
	std::cout << &data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data2->member << std::endl;
	return (0);
}
