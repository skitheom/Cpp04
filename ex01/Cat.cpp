/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:16:10 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:31:16 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain) {
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete this->brain_;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    Brain *newBrain = new Brain(*other.brain_);
    delete this->brain_;
    this->brain_ = newBrain;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }

Brain *Cat::getBrain() { return this->brain_; }

void Cat::setBrain(const Brain &brain) {
  Brain *newBrain = new Brain(brain);
  delete this->brain_;
  this->brain_ = newBrain;
}
