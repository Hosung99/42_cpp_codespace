/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:51:37 by seoson            #+#    #+#             */
/*   Updated: 2023/12/30 21:21:57 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& frag);
		FragTrap&	operator=(const FragTrap& frag);
		void		highFivesGuys(void);
};

#endif
