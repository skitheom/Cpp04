/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:02 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/27 15:37:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: Valid cases ===" << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << "Meta  name: " << meta->getType() << " " << std::endl;
  std::cout << "Dog   name: " << j->getType() << " " << std::endl;
  std::cout << "Cat   name: " << i->getType() << " " << std::endl;
  std::cout << "Meta sound: ";
  meta->makeSound();
  std::cout << "Dog  sound: ";
  j->makeSound();
  std::cout << "Cat  sound: ";
  i->makeSound();

  delete i;
  delete j;
  delete meta;
}

static void test2() {
  std::cout << "\n=== Test case 2: Invalid cases ===" << std::endl;

  const WrongAnimal *meta = new WrongAnimal();
  const WrongAnimal *i = new WrongCat();
  const WrongCat *j = new WrongCat();

  std::cout << "[WrongAnimal] Meta  name: " << meta->getType() << std::endl;
  std::cout << "[WrongAnimal] Cat   name: " << i->getType() << std::endl;
  std::cout << "[WrongCat]    Cat   name: " << j->getType() << std::endl;

  std::cout << "[WrongAnimal] Meta sound: ";
  meta->makeSound();
  std::cout << "[WrongAnimal] Cat  sound: ";
  i->makeSound();
  std::cout << "[WrongCat]    Cat  sound: ";
  j->makeSound();

  delete j;
  delete i;
  delete meta;
}

int main() {
  test1();
  test2();
  return 0;
}
