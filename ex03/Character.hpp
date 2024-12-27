/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:50:12 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 02:33:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
  static const int kMaxMaterias = 4;
  AMateria *inventory_[kMaxMaterias];
  std::string name_;

public:
  Character();
  Character(std::string const &name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  virtual ~Character();

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
