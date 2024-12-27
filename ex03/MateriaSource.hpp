/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:19:07 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 02:33:27 by sakitaha         ###   ########.fr       */
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
};

#endif // MATERIA_SOURCE_HPP
