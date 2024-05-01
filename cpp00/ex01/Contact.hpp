/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:49:40 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/02/27 22:49:40 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<string>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone;
	std::string secret;
	public:
	
	void set_first(std::string str);
	void set_last(std::string str);
	void set_nn(std::string str);
	void set_phone(std::string str);
	void set_secret(std::string str);
	std::string get_first(void);
	std::string get_last(void);
	std::string get_nn(void);
	std::string get_phone(void);
	std::string get_secret(void);
};
#endif