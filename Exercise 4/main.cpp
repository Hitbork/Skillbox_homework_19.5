#include <iostream>
#include <string>
#include <fstream>


// Function to check if file is png
bool checkForPng (char buffer[4]) {
    // Checking for not bytes
    if (buffer[0] != -119) return false;
    if (buffer[1] != 'P') return false;
    if (buffer[2] != 'N') return false;
    if (buffer[3] != 'G') return false;

    // Returning true if bytes are same
    return true;
}


int main() {
    // Greetings
    std::cout << "Defying if file is .png photo\n\n\n" << std::endl;

    // Creating vars
    char buffer1[4], buffer2[4];

    // Creating the flows
    std::ifstream file1("C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 4\\image.png"),
                    file2("C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 4\\notAnImage.txt");

    // Checking if files could be opened
    if (!file1.is_open()) {
        std::cout << "File 1 can't be opened.";
        return 0;
    } else {
        file1.read (buffer1, 4);
    }

    if (checkForPng(buffer1)) {
        std::cout << "File 1 is a png file!\n";
    } else {
        std::cout << "File 1 is not a png file.\n";
    }

    if (!file2.is_open()) {
        std::cout << "File 2 can't be opened.";
        return 0;
    } else {
        file2.read (buffer2, 4);
    }

    if (checkForPng(buffer2)) {
        std::cout << "File 2 is a png file!\n";
    } else {
        std::cout << "File 2 is not a png file.\n";
    }

    return 0;
}
