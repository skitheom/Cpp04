/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:43:30 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:20:31 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain copy constructor called" << std::endl;
  for (size_t i = 0; i < Brain::kMaxIdeas; i++) {
    this->ideas_[i] = other.ideas_[i];
  }
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain copy assignation operator called" << std::endl;
  if (this != &other) {
    for (size_t i = 0; i < Brain::kMaxIdeas; i++) {
      this->ideas_[i] = other.ideas_[i];
    }
  }
  return *this;
}

void Brain::validateIndex(size_t index) const {
  if (index >= Brain::kMaxIdeas) {
    throw std::out_of_range("Index out of range");
  }
}

const std::string &Brain::getIdea(size_t index) const {
  validateIndex(index);
  return this->ideas_[index];
}

void Brain::setIdea(size_t index, const std::string &idea) {
  validateIndex(index);
  this->ideas_[index] = idea;
}
