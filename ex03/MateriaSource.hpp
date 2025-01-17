/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:19:07 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/18 02:30:31 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  static const int kMaxMaterias = 4;
  AMateria *materias_[kMaxMaterias];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  virtual ~MateriaSource();

  virtual void learnMateria(AMateria *materia);
  virtual AMateria *createMateria(std::string const &type);

private:
  void initMaterias();
  void clearMaterias();
  void copyMateriasFrom(const MateriaSource &other);
  void displayErrorMsg(const std::string &msg) const;
};

#endif // MATERIA_SOURCE_HPP
