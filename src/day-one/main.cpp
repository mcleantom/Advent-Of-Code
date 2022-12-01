#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream infile("input.txt");
    std::string line;
    size_t currentCaloriesSum = 0;
    std::vector<double> elfCalories;
    std::make_heap(elfCalories.begin(), elfCalories.end());

    for (std::string line; std::getline(infile, line);) {
        if (line.size() == 0) {
            elfCalories.push_back(currentCaloriesSum);
            std::push_heap(elfCalories.begin(), elfCalories.end());
            currentCaloriesSum = 0;
        }
        else {
            currentCaloriesSum += std::stoi(line);
        }
    };

    

    size_t topKCaloriesSum = 0;

    for (auto i = 0; i < 3; ++i) {
        topKCaloriesSum += elfCalories.front();
        std::pop_heap(elfCalories.begin(), elfCalories.end());
        elfCalories.pop_back();
    };

    std::cout << topKCaloriesSum << std::endl;

    return 0;
}