/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:49:07 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/18 01:25:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : name_("default"), nextStorageIndex_(0) {
  initInventory();
  initStorage();
}

Character::Character(std::string const &name)
    : name_(name), nextStorageIndex_(0) {
  initInventory();
  initStorage();
}

Character::Character(const Character &other)
    : name_(other.name_), nextStorageIndex_(other.nextStorageIndex_) {
  initInventory();
  copyInventoryFrom(other);
  initStorage();
  copyStorageFrom(other);
}

Character::~Character() {
  clearInventory();
  clearStorage();
}

Character &Character::operator=(const Character &other) {
  if (this != &other) {
    this->name_ = other.name_;
    clearInventory();
    copyInventoryFrom(other);
    clearStorage();
    copyStorageFrom(other);
  }
  return *this;
}

std::string const &Character::getName() const { return this->name_; }

void Character::equip(AMateria *m) {
  if (!m) {
    displayErrorMsg("Error: Cannot equip unexisting Materia.");
    return;
  }
  for (int i = 0; i < kMaxMaterias; i++) {
    if (!this->inventory_[i]) {
      this->inventory_[i] = m;
      return;
    }
  }
  displayErrorMsg("Error: Inventory is full, cannot equip Materia.");
}

void Character::unequip(int idx) {
  if (!validateIdx(idx)) {
    return;
  }
  addToStorage(this->inventory_[idx]);
  this->inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (!validateIdx(idx)) {
    return;
  }
  this->inventory_[idx]->use(target);
}

void Character::initInventory() {
  for (int i = 0; i < kMaxMaterias; i++) {
    this->inventory_[i] = 0;
  }
}

void Character::clearInventory() {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (this->inventory_[i]) {
      delete this->inventory_[i];
      this->inventory_[i] = 0;
    }
  }
}

void Character::copyInventoryFrom(const Character &other) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (other.inventory_[i]) {
      this->inventory_[i] = other.inventory_[i]->clone();
    }
  }
}

void Character::initStorage() {
  for (int i = 0; i < kMaxStorage; i++) {
    this->storage_[i] = 0;
  }
}

void Character::clearStorage() {
  for (int i = 0; i < kMaxStorage; i++) {
    if (this->storage_[i]) {
      delete this->storage_[i];
      this->storage_[i] = 0;
    }
  }
}

void Character::copyStorageFrom(const Character &other) {
  for (int i = 0; i < kMaxStorage; i++) {
    if (other.storage_[i]) {
      this->storage_[i] = other.storage_[i]->clone();
    }
  }
}

void Character::addToStorage(AMateria *m) {
  if (!m) {
    displayErrorMsg("Error: Cannot storage unexisting Materia.");
    return;
  }
  if (this->storage_[nextStorageIndex_]) {
    delete this->storage_[nextStorageIndex_];
    this->storage_[nextStorageIndex_] = 0;
  }
  this->storage_[nextStorageIndex_] = m;
  this->nextStorageIndex_ = (nextStorageIndex_ + 1) % kMaxStorage;
}

bool Character::validateIdx(int idx) {
  if (idx < 0 || idx >= kMaxMaterias) {
    displayErrorMsg("Error: Invalid index.");
    return false;
  }
  if (!this->inventory_[idx]) {
    displayErrorMsg("Error: No Materia at the slot.");
    return false;
  }
  return true;
}

void Character::displayErrorMsg(const std::string &msg) const {
#ifdef DISPLAY_MSG
  std::cerr << msg << std::endl;
#else
  (void)msg;
#endif
}
