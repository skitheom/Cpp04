/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:49:07 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 04:35:46 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("default") {
  for (int i = 0; i < kMaxMaterias; i++)
    this->inventory_[i] = 0;
}

Character::Character(std::string const &name) : name_(name) {
  for (int i = 0; i < kMaxMaterias; i++)
    this->inventory_[i] = 0;
}

Character::Character(const Character &other) : name_(other.name_) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (other.inventory_[i])
      this->inventory_[i] = other.inventory_[i]->clone();
    else
      this->inventory_[i] = 0;
  }
}

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    this->name_ = other.name_;
    for (int i = 0; i < kMaxMaterias; i++) {
      if (this->inventory_[i])
        delete this->inventory_[i];
      if (other.inventory_[i])
        this->inventory_[i] = other.inventory_[i]->clone();
      else
        this->inventory_[i] = 0;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (this->inventory_[i])
      delete this->inventory_[i];
  }
}

std::string const &Character::getName() const { return this->name_; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (!this->inventory_[i]) {
      this->inventory_[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || kMaxMaterias <= idx)
    return;
  this->inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || kMaxMaterias <= idx || !this->inventory_[idx])
    return;
  this->inventory_[idx]->use(target);
}
