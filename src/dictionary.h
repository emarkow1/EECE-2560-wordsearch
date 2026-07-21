
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class dictionary {
    public:
        dictionary();
        void readWords(const string& filename);
        void lookupWord(const string& word) const;
        friend ostream& printWords(ostream& os);
    private:
        vector<string> words;
};


#endif