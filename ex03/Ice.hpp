/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:53:30 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/27 21:04:16 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);
  virtual ~Ice();

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif // ICE_HPP
