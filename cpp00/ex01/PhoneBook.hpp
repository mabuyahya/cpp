/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:40:46 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/08/30 16:40:47 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
    private:
        Contact getContact();
        void printContactInfo(Contact contact, int i);
        void printIndexInfo(int i);
        void printColumn(const std::string& str);
        std::string getUserInput(std::string str, int i);
};
#endif