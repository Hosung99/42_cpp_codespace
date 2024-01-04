/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:10:45 by seoson            #+#    #+#             */
/*   Updated: 2024/01/03 22:28:23 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice&				operator=(const Ice& other);
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
