/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:40:44 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/08/30 16:40:45 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0; 
}

void PhoneBook::searchContact()
{
    int index;

    index = this->index > 8 ? 8 : this->index;
    printColumn("index");
    std::cout << "|";
    printColumn("first name");
    std::cout << "|";
    printColumn("last name");
    std::cout << "|";
    printColumn("nick name");
    std::cout << "|";
    std::cout << "\n";
    for (int i = 0; i < index; i++)
        printContactInfo(contacts[i], i);

    int i;
    if (this->index == 0)
        return ;
    while (true) 
    {
        std::cout << "Enter an index:";
        if (std::cin >> i)
        {
            if (i < this->index && i < 8 && i >= 0)
                printIndexInfo(i);
            else
            {
                int temp = (this->index > 7) ? 7 : index;
                std::cout << "Invalid index! the index sould be between " << 0 << " and " << temp - 1 << "\n";
                continue;
            }
            break;
        }
        else
        {
            std::cout << "int input should be integer\n";
            std::cin.clear();
            std::cin.ignore(9999, '\n');
        }
    }
}

void PhoneBook::printColumn(const std::string& str)
{
    std::string temp;
    temp = str;
    if (str.length() > 10)
        temp = str.substr(0, 9) + ".";
    
    std::cout << std::right << std::setw(10) << temp;
}

void PhoneBook::printIndexInfo(int i)
{
    if (i > 7)
        return ; 
    Contact contact = contacts[i];
    std::cout << "first name :"<< contact.getFirstName() << "\n";
    std::cout << "last name :"<< contact.getLastName() << "\n";
    std::cout << "nick name :"<< contact.getNickName()<< "\n";
    std::cout << "darkest secret :"<< contact.getDarkestSecret() << "\n";
    std::cout << "phone number :"<< contact.getPhoneNumber() << "\n";

}

void PhoneBook::printContactInfo(Contact contact, int i)
{
    std::cout << std::right << std::setw(10) << i;
    std::cout << "|";
    printColumn(contact.getFirstName());
    std::cout << "|";
    printColumn(contact.getLastName());
    std::cout << "|";
    printColumn(contact.getNickName());
    std::cout << "|" << "\n";
}

void PhoneBook::addContact()
{
    int index = this->index % 8;
    contacts[index] = getContact();
    this->index++;
}

Contact PhoneBook::getContact()
{
    Contact new_contact;

    new_contact.setFirstName(getUserInput("enter first name(one word only):", 0));
    new_contact.setLastName(getUserInput("enter last name(one word only):", 0));
    new_contact.setNickName(getUserInput("enter nick name(one word only):", 0));
    new_contact.setDarkestSecret(getUserInput("enter darkest secret:", 0));
    new_contact.setPhoneNumber(getUserInput("enter phone number(10-digit number):", 1));
    return (new_contact);
}

static std::string checkIfNum()
{
    std::string input;
    int flag = 1;
    do
    {
        if (flag == 0)
        {
            std::cout << "the input most be 10-digit number\n";
        }
        flag = 1;
        std::cout << "enter phone number(10-digit number):";
        std::cin >> input;
        std::cin.ignore(9999, '\n');
        if (input.length() != 10)
            flag = 0;
        for (unsigned long i = 0; i < input.length(); i++)
        {
            if ((int)input[i] <= '0' || (int) input[i] >= '9')
            {
                i = 0;
                break;
            }
        }
    } while (!flag);
    return (input);
}



std::string PhoneBook::getUserInput(std::string output, int i) 
{
    std::string input;
    if (!i)
        std::cout << output;
    if (i)
        return(checkIfNum());
    else
    {
        std::cin >> input;
        std::cin.ignore(9999, '\n');
    }
    if (std::cin.eof())
    {
        std::cout << "\nEOF detected." << std::endl;
        std::exit(1);
    }
    return (input);
}