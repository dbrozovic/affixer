#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <string>
#include <sstream>

/**
 * Represents a single word in the target language, it contains an element for the root word,
 * its translation into the desired language, and a vector containing its inflected forms.
 */
class Word {
    public:
        std::string root;
        std::string translation;
        std::vector <std::pair <std::string, std::string> > forms;
        Word(std::vector <std::string> fields, std::string csv_line);

        /**
         * Returns a random pair from the forms vector. The first element in the pair contains
         * the name of the inflected form, the second element contains the form itself.
         */
        std::pair <std::string, std::string> getRandomForm();
};

class WordList {
    public:
        WordList(std::string data_file_location);
        Word getIndex(int i) { return contents[i]; }
        int getWordNumber() { return contents.size(); }
        Word getRandomWord();
    private:
        std::vector <Word> contents;
};
