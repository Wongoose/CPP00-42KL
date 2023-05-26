/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwong <zwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:57:01 by zwong             #+#    #+#             */
/*   Updated: 2023/05/26 12:57:01 by zwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		std::exit(EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != 0; j++) {
			std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	std::exit(EXIT_SUCCESS);
}
