#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Greetings
    std::cout << "Searching for words\n\n\n";

    // Creating vars
    int counter = 0;
    std::string word = "so", wordWithDifferentStartLetter, temp;

    // Changing 1st letter for the word to search
    if ((int)word[0] <= 90) {
        // Changing 1st letter to lower
        wordWithDifferentStartLetter = (char)tolower(word[0]) + word.substr(1, word.length()-1);
    } else {
        // Changing 1st letter to upper
        wordWithDifferentStartLetter = (char)toupper(word[0]) + word.substr(1, word.length()-1);
    }

    // Opening file
    std::ifstream words("C:\\Skillbox_repositories\\Skillbox_homework_19.5\\Exercise 1\\words.txt");

    if (!words.is_open()) {
        std::cout << "error\n";
    } else {
        while (!words.eof()) {
            words >> temp;
            if ((temp == word) || (temp == wordWithDifferentStartLetter))
                counter++;
        }
    }

    std::cout << "Word '" << word << "' meets in words.txt " << counter << " times\n";
}
