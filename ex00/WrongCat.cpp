/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:23:10 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 21:25:43 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  if (this != &other) {
    WrongAnimal::operator=(other);
  }
  return *this;
}

void WrongCat::makeSound() const { std::cout << "BadMeow" << std::endl; }
