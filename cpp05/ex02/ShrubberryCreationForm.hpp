/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:30:34 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/12 16:07:42 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

static const std::string ascii_tree = "          .     .  .      +     .      .          .\n     .       .      .     #       .           .\n        .      .         ###            .      .      .\n      .      .   \"#:. .:##\"##:. .:#\"  .      .\n          .      . \"####\"###\"####\"  .\n       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n  .             \"#########\"#########\"        .        \n        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n                .\"##\"#####\"#####\"##\"           .      .\n    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n      .     \"#######\"##\"#####\"##\"#######\"      .     .\n    .    .     \"#####\"\"#######\"\"#####\"    .      .\n            .     \"      000      \"    .     .\n       .         .   .   000     .        .       .\n.. .. ..................O000O........................ ......";


class ShrubberryCreationForm : public AForm
{
	public:
		ShrubberryCreationForm(std::string name);
		~ShrubberryCreationForm();
		ShrubberryCreationForm(const ShrubberryCreationForm&);
		ShrubberryCreationForm&		operator=(const ShrubberryCreationForm&);
		virtual void			execute(Bureaucrat const &) const;
};

#endif