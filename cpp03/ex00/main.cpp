/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:36:11 by seoson            #+#    #+#             */
/*   Updated: 2024/01/02 20:42:46 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("seoson");

	clap.attack("gkwon");
	clap.attack("seoson");
	clap.takeDamage(1);
	clap.beRepaired(1);
	for (int i = 0; i < 12; i++)
		clap.attack("gkwon");
	clap.beRepaired(1);
	return (0);
}
