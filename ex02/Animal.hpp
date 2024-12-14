/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:28 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:52:37 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
  std::string type_;

public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &other);
  virtual ~Animal();

  Animal &operator=(const Animal &other);

  const std::string &getType() const;
  virtual void makeSound() const = 0;
};

#endif // ANIMAL_HPP
