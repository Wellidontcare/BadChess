//
// Created by joris on 17.08.19.
//

#pragma once
#include "../game/Board.h"

namespace chess{
std::vector<Coordinates> parse_input(const std::string& from, const std::string& to);
bool valid_input(const std::string& from, const std::string& to);

const std::map<char, int> number_lookup = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
}
