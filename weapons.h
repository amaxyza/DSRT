#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

class Weapon
{
	std::map<int, std::string> weapon_map;
	std::map<int, int> choice_map;

public:
	Weapon()
	{
		std::ifstream csv("dsr_weapons.csv");

		// load each item from .csv (each item is a weapon) into map for ease of access.

		std::string header_line;
		std::getline(csv, header_line);

		std::string line;
		while (std::getline(csv, line))
		{
			int id;
			std::string weapon_name;


			std::istringstream stream(line);
			std::string token; // for id
			std::getline(stream, token, ',');
			id = std::stoi(token);
			std::getline(stream, weapon_name, ',');
			this->weapon_map[id] = weapon_name;
		}

		// fill choice map
		int counter = 1;
		for (const auto& i : weapon_map)
		{
			choice_map[counter] = i.first;
			counter++;
		}
	}

	void print_weapons()
	{
		for (const auto& i : choice_map)
		{
			std::cout << "[ " << i.first << " ]  " << weapon_map[i.second] << std::endl;
		}
		std::cout << std::endl;
	}

	std::string weapon_from_small_id(int id)
	{
		int true_id = choice_map[id];
		return weapon_map[true_id];
	}

	int small_to_true(int small_id)
	{
		return choice_map[small_id];
	}

	const char** export_weapon_names() {
		const char* weapon_names[241] = {};
		for (int i = 0; i < 241; i++) {
			weapon_names[i] = weapon_from_small_id(i).c_str();
		}

		return weapon_names;
	}
};





