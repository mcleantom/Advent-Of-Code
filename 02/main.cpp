#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <tuple>

enum RockPaperSissors {
    Rock,
    Paper,
    Sissors
};

typedef std::tuple<RockPaperSissors, RockPaperSissors> game;

int main() {
    int lossPoints = 0;
    int drawPoints = 3;
    int winPoints = 6;

    std::unordered_map<RockPaperSissors, int> playerPoints = {
        {Rock, 1},
        {Paper, 2},
        {Sissors, 3}
    };

    std::unordered_map<RockPaperSissors, std::unordered_map<RockPaperSissors, int>> gameMap;
    
    gameMap[Rock] = {
        {Rock, drawPoints},
        {Paper, lossPoints},
        {Sissors, winPoints}
    };
    gameMap[Paper] = {
        {Rock, winPoints},
        {Paper, drawPoints},
        {Sissors, lossPoints}
    };
    gameMap[Sissors] = {
        {Rock, lossPoints},
        {Paper, winPoints},
        {Sissors, drawPoints}
    };

    std::unordered_map<char, RockPaperSissors> cToEnumMap = {
        {'A', Rock},
        {'B', Paper},
        {'C', Sissors},
        {'X', Rock},
        {'Y', Paper},
        {'Z', Sissors}
    };


    std::ifstream infile("input.txt");
    std::string line;
    size_t totalScore = 0;
    for (std::string line; std::getline(infile, line);) {
        RockPaperSissors opponent = cToEnumMap[line[0]];
        RockPaperSissors me = cToEnumMap[line[2]];
        totalScore += gameMap[me][opponent];
        totalScore += playerPoints[me];
    };

    std::cout << totalScore << std::endl;
    return 0;
}