/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:58:58 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:31:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain) {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete this->brain_;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    Brain *newBrain = new Brain(*other.brain_);
    delete this->brain_;
    this->brain_ = newBrain;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }

Brain *Dog::getBrain() { return this->brain_; }

void Dog::setBrain(const Brain &brain) {
  Brain *newBrain = new Brain(brain);
  delete this->brain_;
  this->brain_ = newBrain;
}
