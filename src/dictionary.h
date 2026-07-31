// EECE 2560 Wordsearch Project
// 1-satbermacmar-2b
// dictionary.h
// authors: Jake Berman, Ethan Markow, Donald Mackinnon, Emile Sater
// This file declares the Dictionary class.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "heap.h"

using namespace std;

class Dictionary
// stores the Dictionary list of words in a vector. Includes operations that
// allow reading, printing, sorting, and searching the aforementioned words.
{
    public:
        Dictionary();
        // constructs an empty Dictionary object.

        void readWords(const string& filename);
        // reads the words from "filename" and stores them into the words
        // vector.

        void sortWords(const string& filename);
        // sorts the words using selection sort. writes these sorted words into
        // the file "filename"

        int lookupWord(const string& target) const;
        // locates target in sorted word list using binary search. returns the
        // index of target (if found).

        int partitionWords(int left, int right);
        // rearranges the words around a pivot and returns the location.

        void quicksort(const string& filename);
        // sorts the words using quicksort. writes these sorted words into the
        // file "filename"

        void heapsortWords(const string& filename);
        // sorts the words using heapsort. writes these sorted words into the
        // file "filename"

        friend ostream& operator<<(ostream& os, const Dictionary& dict);
        // writes the words that are stored in dict to os.
    
    private:
        vector<string> words;
        // stores the dictionary words in their original order.

        void quicksortHelper(int left, int right);
        // helper function for quicksort. recursively sorts the vector

}; // end Dictionary class

#endif // DICTIONARY_H