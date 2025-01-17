/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:41 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/28 04:15:50 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
  std::string const type_;

public:
  AMateria(std::string const &type);
  virtual ~AMateria();

  std::string const &getType() const;

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

private:
  AMateria();
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);
};

#endif // A_MATERIA_HPP
