#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { this->current_index_ = 0; }

PhoneBook::~PhoneBook() {}

static int	add_contact_input_loop(std::string &input) {
	while (1) {
		if (!getline(std::cin, input)) return (EXIT_FAILURE);
		if (input.empty())
			std::cout << "Input cannot be empty. Please try again." << std::endl;
		else
			return (EXIT_SUCCESS);
	}
}

static bool	is_number(std::string input) {
  for (int i = 0; input[i]; i++)
    if (!isdigit(input[i])) return false;
  return true;
}

int	PhoneBook::add_contact() {
	Contact	temp;
	std::string	input;

	std::cout << "Enter first name:" << std::endl;
	if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		temp.set_first_name(input);

	std::cout << "Enter last name:" << std::endl;
	if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		temp.set_last_name(input);

	std::cout << "Enter nickname:" << std::endl;
	if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		temp.set_nickname(input);
	
	std::cout << "Enter phone number:" << std::endl;
	while (1) {
		if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		if (is_number(input) == true) break ;
		std::cout << input << " is not a valid phone number. Please try again." << std::endl;
	}
	temp.set_phone_number(input);

	std::cout << "Enter darkest secret:" << std::endl;
	if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		temp.set_darkest_secret(input);

	this->contacts_[this->current_index_] = temp;
	this->current_index_ = (this->current_index_ + 1) % 8;
	return (EXIT_SUCCESS);
	
}

std::string my_truncate(std::string str) {
  if (str.length() > 15) return str.substr(0, 14) + ".";
  return str;
}

static void	print_contact(Contact contact, int i) {
	std::cout << std::right << std::setw(10) << i << " | ";
	std::cout << std::right << std::setw(10) << my_truncate(contact.get_first_name()) << " | ";
	std::cout << std::right << std::setw(10) << my_truncate(contact.get_last_name()) << " | ";
	std::cout << std::right << std::setw(10) << my_truncate(contact.get_nickname()) << std::endl;
}

int	PhoneBook::search_contact() const {
	int	select_i;
	std::string	input;

	// Check if phone book is empty
	if (this->contacts_[0].get_first_name().empty()) {
		std::cout << "Phone book is empty. Cannot search for contact!" << std::endl;
		return (EXIT_SUCCESS);
	}

	// Printing the headers
	std::cout << std::right << std::setw(10) << "Index"
		<< " | ";
	std::cout << std::right << std::setw(10) << "First name"
		<< " | ";
	std::cout << std::right << std::setw(10) << "Last name"
		<< " | ";
	std::cout << std::right << std::setw(10) << "Nickname"
		<< std::endl;

	// Print all contacts to search from
	for (int i = 0; i < 8; i++) {
		if (this->contacts_[i].get_first_name().empty() == false) {
			print_contact(this->contacts_[i], i);
		}
	}

	// Search for specific index
	std::cout << "Enter a contact index to show all details:" << std::endl;
	while (1) {
		if (add_contact_input_loop(input)) return (EXIT_FAILURE);
		select_i = input[0] - 48;
		if (input[1] != 0 || select_i < 0 || select_i > 7 || this->contacts_[select_i].get_first_name().empty()) {
			std::cout << "Invalid index. Try again." << std::endl;
		} else {
			break ;
		}
	}

	std::cout << std::endl << std::left
		<< std::setw(20) << "FIRST NAME: " << this->contacts_[select_i].get_first_name() << std::endl
		<< std::setw(20) << "LAST NAME: " << this->contacts_[select_i].get_last_name() << std::endl
		<< std::setw(20) << "NICKNAME: " << this->contacts_[select_i].get_nickname() << std::endl
		<< std::setw(20) << "PHONE NUMBER: " << this->contacts_[select_i].get_phone_number() << std::endl
		<< std::setw(20) << "DARKEST SECRET: " << this->contacts_[select_i].get_darkest_secret() << std::endl
		<< std::endl;

	return (EXIT_SUCCESS);
}