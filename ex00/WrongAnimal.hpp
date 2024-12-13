/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:18:12 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 21:18:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
  std::string type_;

public:
  WrongAnimal();
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &other);
  ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &other);

  const std::string &getType() const;
  void makeSound() const;
};

#endif // WRONG_ANIMAL_HPP
