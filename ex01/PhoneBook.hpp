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