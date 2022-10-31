#include "../include/word_loader.hpp"

Word::Word(std::vector <std::string> fields, std::string csv_line) {
    
    // creates a new stream object of the csv line to be parsed.
    std::stringstream ss(csv_line);

    getline(ss, this->root, ',');

    getline(ss, this->translation, ',');

    std::string tempString;
    int i = 0;

    // loop through the remainder of the string and writes it to the forms vector.
    while(getline(ss, tempString, ',')) {
        this->forms.push_back(std::make_pair(fields[i], tempString));
        i++;
    }

    return;
}

std::pair <std::string, std::string> Word::getRandomForm() {
    return this->forms[rand() % this->forms.size()];
}

WordList::WordList(std::string data_file_location) {
    std::ifstream data_file(data_file_location);
    
    if (!data_file.is_open()) {
        throw std::runtime_error("Failed to open data file.");
    } else {

        // create a list of fields from the first line of the csv file
        // populate the contents vector based on the remaining lines of the file
        // ???
        // profit
    
        std::vector <std::string> fields;

        std::string unparsed_fields;

        // write the first line of the csv file to unparsed_fields so it can be tokenized.
        getline(data_file, unparsed_fields, '\n');

        // convert the string into a stringstream so it can be tokenized.
        std::stringstream unparsed_fields_ss(unparsed_fields);

        std::string parsed_fields;

        int i = 0;
        while(getline(unparsed_fields_ss, parsed_fields, ',')) {
            // skip the first two entries since we're not interested in them.
            if (i > 1) {
                fields.push_back(parsed_fields);
            }
            i++;
        }

        std::string line;
        for(int i = 0; i < (int) fields.size() && getline(data_file, line, '\n'); i++) {
            this->contents.push_back(Word(fields, line));
        }

        data_file.close();

        return;
    }
}

Word WordList::getRandomWord() {
    return this->getIndex(rand() % contents.size());
}
