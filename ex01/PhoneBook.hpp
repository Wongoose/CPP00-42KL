/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:57:15 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:57:15 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Contact.hpp"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook {
 public:
  PhoneBook();
  ~PhoneBook();
  int add_contact();
  int search_contact() const;

 private:
  Contact contacts_[8];
  int current_index_;
};

#endif