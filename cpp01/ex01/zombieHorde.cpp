/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:35:13 by codespace         #+#    #+#             */
/*   Updated: 2023/12/20 01:48:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];
	for (int zombie_index = 0; zombie_index < N; zombie_index++)
		zombies[zombie_index] = Zombie(name);
	return (zombies);
}
