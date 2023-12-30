/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:36:11 by seoson            #+#    #+#             */
/*   Updated: 2023/12/30 22:16:59 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("frag");
	frag.beRepaired(2147483647);
	for (int i = 0; i < 101; i++)
		frag.attack("frag2");
	frag.takeDamage(50);
	frag.takeDamage(50);
	frag.takeDamage(50);
}
