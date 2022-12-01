#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::ifstream infile("input.txt");
    size_t maxCalorieElf = 1;
    std::string line;
    size_t maxCalories = 0;
    size_t currentCaloriesSum = 0;
    size_t currentElf = 1;

    for (std::string line; std::getline(infile, line);) {
        if (line.size() == 0) {
            if (currentCaloriesSum > maxCalories) {
                maxCalorieElf = currentElf;
                maxCalories = currentCaloriesSum;
            }
            currentCaloriesSum = 0;
            currentElf += 1;
        }
        else {
            currentCaloriesSum += std::stoi(line);
        }
    };


    std::cout << "Max calorie elf: " << maxCalorieElf << std::endl;
    std::cout << "Max calories is: " << maxCalories << std::endl;
    return 0;
}