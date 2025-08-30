/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:37:06 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/08/30 16:37:07 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name,std::string darkest_secret,std::string phone_number)
{
    this->firstName = first_name;
    this->lastName = last_name;
    this->nickName = nick_name;
    this->darkestSecret = darkest_secret;
    this->phoneNumber = phone_number;
}

Contact::Contact()
{
}

void Contact::setFirstName(const std::string& first_name)
{
    this->firstName = first_name;
}

void Contact::setLastName(const std::string& last_name)
{
    this->lastName = last_name;
}

void Contact::setNickName(const std::string& nick_name)
{
    this->nickName = nick_name;
}

void Contact::setDarkestSecret(const std::string& darkest_secret)
{
    this->darkestSecret = darkest_secret;
}

void Contact::setPhoneNumber(const std::string& phone_number)
{
    this->phoneNumber = phone_number;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}