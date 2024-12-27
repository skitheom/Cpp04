/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:47:40 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 04:16:13 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type_("unknown") {}

AMateria::AMateria(std::string const &type) : type_(type) {}

AMateria::AMateria(const AMateria &other) : type_(other.type_) {}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this != &other) {
  }
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return this->type_; }

void AMateria::use(ICharacter &target) {
  std::cout << "* use Materia on " << target.getName() << " *" << std::endl;
}