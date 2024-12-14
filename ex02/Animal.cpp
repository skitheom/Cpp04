/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:21:59 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:53:11 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type_(type) {
  std::cout << "Animal custom constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type_(other.type_) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

const std::string &Animal::getType() const { return this->type_; }
