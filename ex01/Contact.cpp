/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:57:06 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:57:06 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::get_first_name(void) const{ 
	return (this->first_name_);
}
std::string Contact::get_last_name(void) const{ 
	return (this->last_name_);
}
std::string Contact::get_nickname(void) const{ 
	return (this->nickname_);
}
std::string Contact::get_phone_number(void) const{ 
	return (this->phone_number_);
}
std::string Contact::get_darkest_secret(void) const{
  return (this->darkest_secret_);
}
void Contact::set_first_name(std::string first_name) {
	this->first_name_ = first_name;
}
void Contact::set_last_name(std::string last_name) {
	this->last_name_ = last_name;
}
void Contact::set_nickname(std::string nickname) {
	this->nickname_ = nickname;
}
void Contact::set_phone_number(std::string phone_number) {
	this->phone_number_ = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret) {
	this->darkest_secret_ = darkest_secret;
}