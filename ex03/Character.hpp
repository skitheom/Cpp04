/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:50:12 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/18 01:26:21 by sakitaha         ###   ########.fr       */
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
  static const int kMaxStorage = 32;

  std::string name_;
  AMateria *inventory_[kMaxMaterias];
  AMateria *storage_[kMaxStorage];
  int nextStorageIndex_;

public:
  Character();
  Character(std::string const &name);
  Character(const Character &other);
  ~Character();

  Character &operator=(const Character &other);

  std::string const &getName() const;

  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  void initInventory();
  void clearInventory();
  void copyInventoryFrom(const Character &other);
  void initStorage();
  void clearStorage();
  void copyStorageFrom(const Character &other);
  void addToStorage(AMateria *m);
  bool validateIdx(int idx);
  void displayErrorMsg(const std::string &msg) const;
};

#endif // CHARACTER_HPP
