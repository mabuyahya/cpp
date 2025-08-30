/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:59:37 by mabuyahy          #+#    #+#             */
/*   Updated: 2025/08/30 17:37:55 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t now;
    time(&now);
    tm *struct_time = localtime(&now);
    std::cout << "[" 
              << 1900 + struct_time->tm_year 
              << std::setfill('0') << std::setw(2) << 1 + struct_time->tm_mon
              << std::setfill('0') << std::setw(2) << struct_time->tm_mday 
              << "_"
              << std::setfill('0') << std::setw(2) << struct_time->tm_hour
              << std::setfill('0') << std::setw(2) << struct_time->tm_min
              << std::setfill('0') << std::setw(2) << struct_time->tm_sec 
              << "] ";
}
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << "\n";
}
int Account::getNbAccounts()
{
    return (_nbAccounts);
}
int Account::getTotalAmount()
{
    return (_totalAmount);
}
int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}
void    Account::makeDeposit(int deposit)
{
    _totalAmount += deposit;
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << "\n";
}
bool    Account::makeWithdrawal(int withdrawal)
{
    if (_amount >= withdrawal)
    {
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
			  << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
        return (true);
    }
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << "\n";
    return(false);
}
int Account::checkAmount() const
{
    return(_amount);
}
void Account::displayAccountsInfos()
{
    _displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << "\n";

}
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << "\n";
}
