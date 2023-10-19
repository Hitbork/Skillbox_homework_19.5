#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Greetings
    std::cout << "Opening the file\n\n\n" << std::endl;

    // Creating vars
    std::string path, temp;

    // Requesting the path to the file
    std::cout << "Write a path to the file you wish to open:\n";
    std::getline(std::cin, path);
    std::cout << "\n";

    // Opening the file
    std::ifstream file(path);

    // Check if file could be opened
    if (!file.is_open()) {
        std::cout << "There is an error to open " << path << " path. Please, try again";
        return 1;
    } else {
        // Reading text from the file
        while (std::getline(file, temp)) {
            std::cout << temp << std::endl;
        }
    }
    std::cout << std::endl;
    file.seekg(0);
    file.close();
    return 0;
}
