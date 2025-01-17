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

class ICharacter;

class Ice : public AMateria {
public:
  Ice();
  ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);

private:
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);
};

#endif // ICE_HPP
