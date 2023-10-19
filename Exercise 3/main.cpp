#include <iostream>
#include <string>
#include <fstream>

int main() {
    // Greetings
    std::cout << "Reading the statement\n\n\n";

    // Creating vars
    std::string name, secondName, fullNameOfMaxPayer, date, dateOfMaxValue;
    double value, maxValue = 0, sumValue = 0;

    // Creating flow
    std::ifstream file("C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 3\\info.txt");

    // Check if flow could be opened
    if (!file.is_open()) {
        std::cout << "There is an error in opening the file!";
        return 1;
    } else {
        // Reading the flow
        while (!file.eof()) {
            file >> name >> secondName >> value >> date;
            sumValue += value;
            if (value > maxValue) {
                maxValue = value;
                fullNameOfMaxPayer = name + " " + secondName;
                dateOfMaxValue = date;
            }
        }
    }

    // Outputting the information
    std::cout << "Summary value of paying: " << sumValue << std::endl;
    std::cout << "Human with maximum payout amount is " << fullNameOfMaxPayer << ". He payed " << maxValue << " in " << dateOfMaxValue << std::endl;

    return 0;
}