/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:22:32 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 04:35:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < kMaxMaterias; i++) {
    this->materias_[i] = 0;
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (other.materias_[i])
      this->materias_[i] = other.materias_[i]->clone();
    else
      this->materias_[i] = 0;
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < kMaxMaterias; i++) {
      if (this->materias_[i])
        delete this->materias_[i];
      if (other.materias_[i])
        this->materias_[i] = other.materias_[i]->clone();
      else
        this->materias_[i] = 0;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < kMaxMaterias; i++) {
    delete this->materias_[i];
  }
}

void MateriaSource::learnMateria(AMateria *materia) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (!this->materias_[i]) {
      this->materias_[i] = materia->clone();
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (this->materias_[i] && this->materias_[i]->getType() == type) {
      return this->materias_[i]->clone();
    }
  }
  return 0;
}
