#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Greetings
    std::cout << "Searching for words\n\n\n";

    // Creating vars
    int counter = 0;
    std::string word = "so", temp;

    // Opening file
    std::ifstream words("C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 1\\words.txt");

    if (!words.is_open()) {
        std::cout << "error\n";
    } else {
        while (!words.eof()) {
            words >> temp;
            if (temp == word)
                counter++;
        }
    }

    std::cout << "Word '" << word << "' meets in words.txt " << counter << " times\n";
}
