/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:14:21 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:31:00 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *brain_;

public:
  Cat();
  Cat(const Cat &other);
  ~Cat();

  Cat &operator=(const Cat &other);

  void makeSound() const;

  Brain *getBrain();
  void setBrain(const Brain &brain);
};

#endif // CAT_HPP
