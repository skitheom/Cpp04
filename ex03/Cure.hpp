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

class ICharacter;

class Cure : public AMateria {
public:
  Cure();
  ~Cure();

  AMateria *clone() const;
  void use(ICharacter &target);

private:
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
};

#endif // CURE_HPP
