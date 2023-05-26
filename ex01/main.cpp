/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:57:10 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:57:10 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook phone_book;
	std::string	input;

	std::cout << "Welcome to your Phone Book!" << std::endl;
	std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	while (getline(std::cin, input)) {
		if (input == "ADD") {
			if (phone_book.add_contact()) {
				std::cout << "Failed adding contact. Exiting program!" << std::endl;
				return (EXIT_FAILURE);
			}
		} else if (input == "SEARCH") {
			if (phone_book.search_contact()) {
				std::cout << "Failed to search. Exiting program!" << std::endl;
				return (EXIT_FAILURE);
			}
		} else if (input == "EXIT") {
			break ;
		} else {
			std::cout << "Invalid input. Please try again!" << std::endl;
		}
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Goodbye. Exiting program!" << std::endl;
}