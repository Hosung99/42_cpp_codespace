/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:27:08 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 11:54:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombies = zombieHorde(ZOMBIE_COUNT, "seoson");
	for (int zombie_index = 0; zombie_index < ZOMBIE_COUNT; zombie_index++)
		zombies[zombie_index].announce();
	delete [] zombies;
	zombies = NULL;
	return (0);
}
