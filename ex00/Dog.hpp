/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:56:29 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 21:08:09 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  virtual ~Dog();

  Dog &operator=(const Dog &other);

  virtual void makeSound() const;
};

#endif // DOG_HPP
