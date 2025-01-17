/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:22:32 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/18 03:01:46 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() { initMaterias(); }

MateriaSource::MateriaSource(const MateriaSource &other) {
  initMaterias();
  copyMateriasFrom(other);
}

MateriaSource::~MateriaSource() { clearMaterias(); }

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    clearMaterias();
    copyMateriasFrom(other);
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
  if (!materia) {
    displayErrorMsg("Error: Cannot learn unexisting Materia.");
    return;
  }
  for (int i = 0; i < kMaxMaterias; i++) {
    if (!this->materias_[i]) {
      this->materias_[i] = materia;
      return;
    }
  }
  displayErrorMsg("Error: Materia Source is full, cannot learn Materia.");
  delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type.empty()) {
    displayErrorMsg("Error: Type cannot be empty.");
    return 0;
  }
  for (int i = 0; i < kMaxMaterias; i++) {
    if (this->materias_[i] && this->materias_[i]->getType() == type) {
      AMateria *cloned = this->materias_[i]->clone();
      if (!cloned) {
        displayErrorMsg("Error: Failed to clone Materia.");
        return 0;
      }
      return cloned;
    }
  }
  displayErrorMsg("Error: Cannot find specified type Materia.");
  return 0;
}

void MateriaSource::initMaterias() {
  for (int i = 0; i < kMaxMaterias; i++) {
    this->materias_[i] = 0;
  }
}

void MateriaSource::clearMaterias() {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (this->materias_[i]) {
      delete this->materias_[i];
      this->materias_[i] = 0;
    }
  }
}

void MateriaSource::copyMateriasFrom(const MateriaSource &other) {
  for (int i = 0; i < kMaxMaterias; i++) {
    if (other.materias_[i]) {
      this->materias_[i] = other.materias_[i]->clone();
      if (!this->materias_[i])
        displayErrorMsg("Error: Failed to clone Materia.");
    }
  }
}

void MateriaSource::displayErrorMsg(const std::string &msg) const {
#ifdef DISPLAY_MSG
  std::cerr << msg << std::endl;
#else
  (void)msg;
#endif
}
