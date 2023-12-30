/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:36:11 by seoson            #+#    #+#             */
/*   Updated: 2023/12/30 22:13:40 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("scav1");
	scav.takeDamage(200);
	scav.takeDamage(200);
	scav.guardGate();
	for (int i = 0; i < 52; i++)
		scav.attack();
	scav.guardGate();
}
