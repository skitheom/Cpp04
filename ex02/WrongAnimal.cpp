/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:15:44 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 21:18:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
  std::cout << "WrongAnimal custom constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

const std::string &WrongAnimal::getType() const { return this->type_; }

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound" << std::endl;
}
