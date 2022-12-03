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

    while (infile.peek() != EOF) {
        std::vector<std::set<char>> badges(3);
        for (auto i=0; i<3; ++i) {
            std::getline(infile, line);
            for (auto c : line) {
                badges[i].insert(c);
            }
        }
        std::set<char> abIntersection;
        std::set_intersection(
            badges[0].begin(), badges[0].end(),
            badges[1].begin(), badges[1].end(),
            std::inserter(abIntersection, abIntersection.begin())
        );
        std::set_intersection(
            abIntersection.begin(), abIntersection.end(),
            badges[2].begin(), badges[2].end(),
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
