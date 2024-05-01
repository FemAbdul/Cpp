/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabdul-k <fabdul-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:43:27 by fabdul-k          #+#    #+#             */
/*   Updated: 2024/03/11 08:43:27 by fabdul-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<fstream>
#include<cctype>

int main(int argc,char **argv)
{
	if (argc != 4)
	{
		std::cout<<"Wrong Number of arguments!!"<<std::endl;
		return (1);
	}

	std::string file_name(argv[1]);
	std::string s1(argv[2]);
	std::string rep_str(argv[3]);

	std::ifstream Myfile(file_name.c_str()); //we use c_str() to convert string to const char*
	if (!Myfile.is_open())
	{
		std::cout<<"Error!! Could not open the file"<<std::endl;
		return (1);
	}
	std::string line;
	file_name.append(".replace");
	std::ofstream new_file(file_name.c_str());
	size_t pos = 0;
	
	while (std::getline(Myfile, line))
	{
		if (line.empty())
			new_file<<'\n';
		else
		{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, rep_str);
			pos = line.find(s1, pos + rep_str.length());
		}
		if (Myfile.eof())
			new_file<<line;
		else
			new_file<<line<<'\n';
		}
	}
	Myfile.close();
	new_file.close();
}