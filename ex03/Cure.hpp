/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:01:32 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/27 21:04:15 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
  virtual ~Cure();

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif // CURE_HPP
