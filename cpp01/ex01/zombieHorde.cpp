/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:35:13 by codespace         #+#    #+#             */
/*   Updated: 2024/01/08 09:57:13 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* zombies = new Zombie[N];
	for (int zombie_index = 0; zombie_index < N; zombie_index++)
		zombies[zombie_index].setName(name);
	return (zombies);
}
