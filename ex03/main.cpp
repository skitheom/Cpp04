/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:38:31 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/18 03:00:51 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void sampleTest() {
  std::cout << "== Sample Test ==" << std::endl;
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
}

static void edgeCaseTest() {
  std::cout << "== Edge Case Test ==" << std::endl;

  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");

  for (int i = 0; i < 4; ++i) {
    AMateria *tmp = src->createMateria(i % 2 == 0 ? "ice" : "cure");
    me->equip(tmp);
  }
  me->equip(src->createMateria("ice"));
  for (int i = -1; i < 5; i++) {
    me->use(i, *me);
  }
  me->unequip(0);
  me->unequip(1);
  delete me;
  delete src;
}

int main() {
  sampleTest();
  edgeCaseTest();
}
