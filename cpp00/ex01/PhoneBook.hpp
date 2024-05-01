/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:31:14 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/02/27 08:31:14 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include<iostream>
#include<iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
	int index;
	int oldest;
	Contact contacts[8];
	public:
	PhoneBook(void);
	// ~Phonebook(void);
	void add_contact(void);
	void display_list(void);
	void search(void);
};

#endif