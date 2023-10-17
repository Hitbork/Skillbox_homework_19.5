#include <iostream>
#include <fstream>
#include <string>

void outputOfScore(int &pointsOfExperts, int &pointsOfTVViewers) {
    std::cout << "\t      SCORE:\n";
    std::cout << "     Experts:\t   TV viewers:\n";
    std::cout << "\t" << pointsOfExperts << "\t\t" << pointsOfTVViewers << "\n\n\n";
}

void defyingTheSector(int &pointer, bool questions[]) {
    int offset;
    std::cout << "Write offset for the pointer:\n";
    std::cin >> offset;
    std::cout << "\n";

    pointer = (pointer + offset) % 12;

    while (questions[pointer]) pointer = (pointer + 1) % 12;

    questions[pointer] = true;

    std::cout << "Question " << pointer+1 << " on the table!\n\n";
 }

 void outputtingTheText(int &pointer, std::string &text, std::string &baseForPath, bool isQuestion) {
     // Creating flow
     std::ifstream file(baseForPath + std::to_string(pointer+1) + ".txt");

     // Check if file can be opened
     if (!file.is_open()) {
         std::cout << "The file can't be opened";
     } else {
         // Reading text from the file
         if (isQuestion) {
             while (std::getline(file, text)) {
                 std::cout << text << std::endl;
             }
         } else {
             std::getline(file, text);
         }
         file.close();
     }
}

int main() {
    // Greetings
    std::cout << "What, where, when?\n\n\n" << std::endl;

    // Creating vars
    bool questions[13];
    int pointsOfExperts = 0, pointsOfTVViewers = 0, pointer = 0;
    std::string text, currentQuestion, answerForQuestion,
                baseForQuestions = "C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 4\\Questions\\Question_",
                baseForAnswers = "C:\\Skillbox_github\\Homework 19.5\\Skillbox_homework_19.5\\Exercise 4\\Answers\\Answer_";

    // Filling the arrays with "False", because if questions would be asked it'll get tagged as "True"
    for (int i = 0; i < 13; i++) {
        questions[i] = false;
    }

    // Cycle of the game
    while (pointsOfExperts < 6 && pointsOfTVViewers < 6) {
        // Outputting the score and defying current sector
        outputOfScore(pointsOfExperts, pointsOfTVViewers);

        std::cout << "---------------------------------------------\n";

        defyingTheSector(pointer, questions);

        // Outputting the question to the table
        outputtingTheText(pointer, text, baseForQuestions, true);

        // Requesting the answer
        std::cout << "\nInput the answer:\n";
        std::cin >> answerForQuestion;
        std::cout << "\n";

        // Outputting the real answer
        outputtingTheText(pointer, text, baseForAnswers, false);

        // Checking if answer is right
        if (text == answerForQuestion) {
            std::cout << "Answer is right!\n";
            std::cout << "Adding point to the experts!\n";
            pointsOfExperts += 1;
        } else {
            std::cout << "Answer is wrong!\n";
            std::cout << "Adding point to the TV viewers\n";
            pointsOfTVViewers += 1;
        }

        std::cout << "---------------------------------------------\n\n\n";
    }

    outputOfScore(pointsOfExperts, pointsOfTVViewers);
    std::cout << "\n\n";

    if (pointsOfExperts == 6) {
        std::cout << "\tExperts are the winners!\n";
    } else {
        std::cout << "\tTV viewers are the winners!\n";
    }

    return 0;
}
