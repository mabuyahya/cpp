/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:40:40 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/08/30 16:40:41 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"



int main()
{
    PhoneBook pb;
    std::string cmd;
    while (true)
    {
        std:: cout << "\033[1;31mYou have just three commands 'ADD' 'SEARCH' 'EXIT'" << "\n";
		std:: cout << "please enter one of these commands : \033[0m";
        std::cin >> cmd;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
            pb.searchContact();
        else if (cmd == "EXIT")
            break;
    }
}

