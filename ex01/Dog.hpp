/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:56:29 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:31:08 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain_;

public:
  Dog();
  Dog(const Dog &other);
  ~Dog();

  Dog &operator=(const Dog &other);

  void makeSound() const;

  Brain *getBrain();
  void setBrain(const Brain &brain);
};

#endif // DOG_HPP
