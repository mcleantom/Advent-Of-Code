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

enum GameResult {
    Loss,
    Draw,
    Win
};

int main() {
    std::unordered_map<GameResult, int> resultToPoints;
    resultToPoints[Loss] = 0;
    resultToPoints[Draw] = 3;
    resultToPoints[Win] = 6;

    std::unordered_map<RockPaperSissors, int> playerPoints = {
        {Rock, 1},
        {Paper, 2},
        {Sissors, 3}
    };

    std::unordered_map<RockPaperSissors, std::unordered_map<RockPaperSissors, int>> gameMap;
    
    gameMap[Rock] = {
        {Rock, Draw},
        {Paper, Loss},
        {Sissors, Win}
    };
    gameMap[Paper] = {
        {Rock, Win},
        {Paper, Draw},
        {Sissors, Loss}
    };
    gameMap[Sissors] = {
        {Rock, Loss},
        {Paper, Win},
        {Sissors, Loss}
    };

    std::unordered_map<RockPaperSissors, std::unordered_map<GameResult, RockPaperSissors>> inverseGameMap;

    inverseGameMap[Rock] = {
        {Loss, Sissors},
        {Draw, Rock},
        {Win, Paper}
    };
    inverseGameMap[Paper] = {
        {Loss, Rock},
        {Draw, Paper},
        {Win, Sissors}
    };
    inverseGameMap[Sissors] = {
        {Loss, Paper},
        {Draw, Sissors},
        {Win, Rock}
    };

    std::unordered_map<char, RockPaperSissors> cToEnumMap = {
        {'A', Rock},
        {'B', Paper},
        {'C', Sissors},
        {'X', Rock},
        {'Y', Paper},
        {'Z', Sissors}
    };

    std::unordered_map<char, GameResult> cToGameResult = {
        {'X', Loss},
        {'Y', Draw},
        {'Z', Win}
    };

    std::ifstream infile("input.txt");
    std::string line;
    size_t totalScore = 0;
    for (std::string line; std::getline(infile, line);) {
        RockPaperSissors opponent = cToEnumMap[line[0]];
        GameResult result = cToGameResult[line[2]];
        RockPaperSissors me = inverseGameMap[opponent][result];
        totalScore += resultToPoints[result];
        totalScore += playerPoints[me];
    };

    std::cout << totalScore << std::endl;
    return 0;
}