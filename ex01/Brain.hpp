/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:44:15 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/13 23:19:18 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
  static const size_t kMaxIdeas = 100;
  std::string ideas_[kMaxIdeas];

  void validateIndex(size_t index) const;

public:
  Brain();
  Brain(const Brain &other);
  ~Brain();

  Brain &operator=(const Brain &other);

  const std::string &getIdea(size_t index) const;
  void setIdea(size_t index, const std::string &idea);
};

#endif // BRAIN_HPP
