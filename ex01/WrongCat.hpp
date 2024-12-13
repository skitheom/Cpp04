/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:14:23 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 21:23:22 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);
  ~WrongCat();

  WrongCat &operator=(const WrongCat &other);

  void makeSound() const;
};

#endif // WRONG_CAT_HPP
