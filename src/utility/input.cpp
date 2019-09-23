//
// Created by joris on 17.08.19.
//

#include "input.h"
namespace chess
{
//converts the string input to coordinates
std::vector<Coordinates> parse_input(const std::string &from, const std::string &to)
{
    int x1 = from[0] > 'h' ? 10 : number_lookup.at(from[0]);
    int y1 = BOARD_WIDTH - (from[1] - '0');
    int x2 = to[0] > 'h' ? 10 : number_lookup.at(to[0]);
    int y2 = BOARD_WIDTH - (to[1] - '0');
    return {{x1, y1},
            {x2, y2}};
}

//checks whether the each input is only two characters, with the first character being a letter and the second a single digit
bool valid_input(const std::string &from, const std::string &to)
{
    return !(from.size() > 2 || to.size() > 2 || !isalpha(from[0]) || !isalpha(to[0]) || !isdigit(from[1])
        || !isdigit(to[1]));
}
}
