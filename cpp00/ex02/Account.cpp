/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:51:56 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/02 12:51:56 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include<iostream>
#include<iomanip>
#include<ctime>

//initialising static attributes

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//getfunctions for private attributes

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}


//Constructor

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_nbAccounts += 1;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
	std::cout<<"index:"<<_accountIndex<<";"
	<<"amount:"<<_amount<<";"<<"created"<<std::endl;
}

//Destructor

Account::~Account()
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"
	<<"amount:"<<_amount<<";"<<"closed"<<std::endl;
}


void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";"
			<<"total:"<<getTotalAmount()<<";"
			<<"deposits:"<<getNbDeposits()<<";"
			<<"withdrawals:"<<getNbWithdrawals();
	std::cout<<std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "deposits:" << this->_nbDeposits << ";"
         << "withdrawals:" << this->_nbWithdrawals <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	
	this->_nbDeposits = 1;
	_totalNbDeposits+=_nbDeposits;
	 _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";"
         << "deposit:" << deposit<< ";";
	this->_amount+= deposit;
	this->_totalAmount+=deposit;
	std::cout<<"amount:"<<this->_amount<<";"
         << "nb_deposits:" << this->_nbDeposits<<std::endl;
}

int Account::checkAmount(void) const
{
	if (_amount < 0)
		return (1);
	return (0);

}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount << ";";
	this->_amount-= withdrawal;
	if (checkAmount())
	{
		this->_amount+= withdrawal;
		this->_nbWithdrawals = 0;
		std::cout<<"withdrawal:refused"<<std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals+=_nbWithdrawals;
	this->_totalAmount-=withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";"
         << "amount:" << this->_amount << ";"
         << "nb_withdrawals:" << this->_nbWithdrawals <<std::endl;
	return (true);
}

void Account::_displayTimestamp(void)
{
    time_t      t_ptr;
    struct tm   *t_stmp;

    std::time(&t_ptr);
    t_stmp = localtime(&t_ptr);
    std::cout<< "[";
    std::cout<< t_stmp->tm_year + 1900;
    std::cout<< std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
    std::cout<< std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
    std::cout<< std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
    std::cout<< std::setw(2) << std::setfill('0') << t_stmp->tm_min;
    std::cout<< std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
    std::cout<< "] ";
}