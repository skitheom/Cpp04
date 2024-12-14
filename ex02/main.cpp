/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:02 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:56:29 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void test1() {
  std::cout << "\n=== Test case 1: ===" << std::endl;
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << "Dog   name: " << j->getType() << " " << std::endl;
  std::cout << "Cat   name: " << i->getType() << " " << std::endl;

  std::cout << "Dog  sound: ";
  j->makeSound();
  std::cout << "Cat  sound: ";
  i->makeSound();

  delete j;
  delete i;
}

static void test2() {
  std::cout << "\n=== Test case 2: ===" << std::endl;
  const size_t maxAnimalCount = 3;
  Animal *animals[maxAnimalCount];

  for (size_t i = 0; i < maxAnimalCount; i++) {
    if (i % 2 == 0) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }
  for (size_t i = 0; i < maxAnimalCount; i++) {
    std::cout << "Name: " << animals[i]->getType() << ", Sound: ";
    animals[i]->makeSound();
  }
  for (size_t i = 0; i < maxAnimalCount; i++) {
    delete animals[i];
  }
}

static void test3() {
  std::cout << "\n=== Test case 3: Deep Copy Test ===" << std::endl;

  Cat basic;

  std::cout << "Original Name: " << basic.getType() << ", Sound: ";
  basic.makeSound();

  try {
    basic.getBrain()->setIdea(0, "I am a basic cat");
  } catch (const std::out_of_range &e) {
    std::cout << "[Exception in setIdea] " << e.what() << std::endl;
  }

  {
    Cat tmp = basic;
    std::cout << "Copy Name: " << tmp.getType() << ", Sound: ";
    tmp.makeSound();

    try {
      tmp.getBrain()->setIdea(0, "I am a copy cat!");
      std::cout << "Modified Copy Brain[0]: " << tmp.getBrain()->getIdea(0)
                << std::endl;
      std::cout << "Original Brain[0]: " << basic.getBrain()->getIdea(0)
                << std::endl;
    } catch (const std::out_of_range &e) {
      std::cout << "[Exception] " << e.what() << std::endl;
    }
  }
  std::cout << "After Scope: Name: " << basic.getType() << ", Sound: ";
  basic.makeSound();
}

int main() {
  // Animal animal; // エラーになる
  test1();
  test2();
  test3();
  return 0;
}
