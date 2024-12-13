/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:58:58 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 18:12:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
