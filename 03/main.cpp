#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include <numeric>

int main() {
    std::ifstream infile("input.txt");
    std::string line;
    std::vector<char> uniques;

    for (std::string line; std::getline(infile, line);) {
        std::set<char> uniquesLeft, uniquesRight;
        std::vector<char> both;
        for (auto c : line.substr(0, line.size()/2)) {
            uniquesLeft.insert(c);
        };
        for (auto c : line.substr(line.size()/2)) {
            uniquesRight.insert(c);
        }
        std::set_intersection(
            uniquesLeft.begin(), uniquesLeft.end(),
            uniquesRight.begin(), uniquesRight.end(),
            std::back_inserter(uniques)
        );
    }
    size_t sum = 0;
    for (auto c : uniques) {
        if (int(c) < int('a')) {
            sum += int(c) - int('A') + 27;
        }
        else {
            sum += int(c) - int('a') + 1;
        }
    }

    std::cout << sum << std::endl;
}
