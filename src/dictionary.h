
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class Dictionary {
    public:
        Dictionary();
        void readWords(const string& filename);
        void sortWords(const string& filename);
        void sortStandard(const string& filename);
        void lookupWord(const string& word) const;
        friend ostream& operator<<(ostream& os, const Dictionary& dict);
    private:
        vector<string> words;

        string makeSortKey(const string& word);
        bool comesBefore(const string& left, const string& right);
};


#endif