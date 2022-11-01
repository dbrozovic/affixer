/**
 * Author: Daniel Brozovic
 * Date: 10/31/2022
 *
 * A simple application to practice verb conjugation and noun declension.
 */

#include <cmath>

#include "../include/word_loader.hpp"

int main(int argc, char **argv) {
    srand(time(0));

    std::string path;
    int times; // if times is initialized to 0 or below, the program will continue forever.

    if (argc != 3) {
        std::cout << "File to load words from: ";
        std::cin >> path;
        std::cout << "Number of words to practice: ";
        std::cin >> times;
    } else {
        path = argv[1];
        times = atoi(argv[2]);
        // TODO: add support for loading multiple files via command line argument.
    }

    WordList words(path);

    int correct = 0;
    int incorrect = 0;
    int i = 0;
    while (i < times || times <= 0) {
        std::string guess;
        
        // get a random index from the words object, we're storing it here so that we can tell
        // what the root form of the word is.
        int randIndex = rand() % words.getWordNumber();
        std::string root = words.getIndex(randIndex).root;

        std::pair <std::string, std::string> form = words.getIndex(randIndex).getRandomForm();
        
        std::cout << "Write " << root << " in the " << form.first << ".\n";
        std::cin >> guess;

        if (guess == "q") {
            break;
        }

        if (guess == form.second) {
            std::cout << "Correct!\n";
            correct++;
        } else {
            std::cout << "Incorrect. The correct answer was " << form.second << ".\n";
            incorrect++;
        }

        i++;
    }

    std::cout << "You got " << correct << " out of " << correct + incorrect << ".\n";
    std::cout << "That's a " << round(100 * (correct / (float) (correct + incorrect))) << "%.\n";

    return 0;
}
