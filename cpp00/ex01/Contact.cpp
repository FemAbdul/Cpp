/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:52:54 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/02/29 10:52:54 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first(std::string str)
{
	this->first_name = str;
}

void Contact::set_last(std::string str)
{
	this->last_name = str;
}

void Contact::set_nn(std::string str)
{
	this->nick_name = str;
}

void Contact::set_secret(std::string str)
{
	this->secret = str;
}

void Contact::set_phone(std::string str)
{
	this->phone = str;
}

std::string Contact::get_first(void)
{
	return (this->first_name);
}

std::string Contact::get_last(void)
{
	return (this->last_name);
}

std::string Contact::get_nn(void)
{
	return (this->nick_name);
}

std::string Contact::get_phone(void)
{
	return (this->phone);
}

std::string Contact::get_secret(void)
{
	return (this->secret);
}
