// EECE 2560 Wordsearch Project
// 1-satbermacmar-2a
// dictionary.cpp
//
// This file implements the Dictionary class function that is in charge of
// reading, sorting, timing, searching, and printing the required word list.
//

#include "dictionary.h"
#include "d_except.h"
#include <algorithm>
#include <chrono>

using namespace std;

Dictionary::Dictionary()
//Initializes an empty Dictionary object
{
}

void Dictionary::readWords(const string& filename)
// readWords intakes the name of the dictionary txt file, opens it, and reads
// the words then stores them in a words vector.
{  
    ifstream fin;
    string fileName = filename;
    fin.open(fileName.c_str());

    if (!fin) {
        throw fileOpenError(filename);
    }

    string word;

    //Stores each word as they appear in the input file
    while (fin >> word)
    {
        words.push_back(word);
    } // end while

    fin.close();
} // end readWords

void Dictionary::sortWords(const string& filename) 
// sortWords intakes the name of the dictionary txt file, opens it, and sorts,
// the words using selectionsort and rewrites the sorted words to the txt file.
// This function also uses the chrono class to record the time the sorting
// takes and prints the runtime to console.
{
    auto start = chrono::system_clock::now();
    ofstream fout;
    string fileName = filename;
    fout.open(fileName.c_str());

    if (!fout)
    {
        throw fileOpenError(filename);
    }

    //using selection sort to place the rest of the minimum words next.
    for (int i = 0; i < (words.size() - 1); i++)
    {
        int min = i;

        for (int j = i + 1; j < words.size(); j++)
        {
            if (words[j] < words[min])
            {
                min = j;
            }
        } // end for

        swap(words[i], words[min]);
    } // end for

    // Writes each sorted word on its own line.
    for (int i = 0; i < words.size(); i++)
    {
        fout << words[i] << endl;
    } // end for

    fout.close();

    auto end = chrono::system_clock::now();
    
    cout << "Runtime: "
    << chrono::duration_cast<chrono::seconds>(end - start).count()
    << " s" << std::endl;
} // end sortWords

int Dictionary::lookupWord(const string& target) const
// lookupWord function takes the target word in the form of a string and
// uses binary search to search through the word list and then returns the
// index in which the target word is located within the dictionary object.
// If unsuccessful, returns -1.
{
    int first = 0;
    int last = words.size() - 1;

    // keeps on repeating the half of the search that can't contain the target.
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        string midValue = words[mid];

        if (target == midValue)
        {
            return mid;
        }
        else if (target < midValue)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    } // end while

    return -1; 
} // end lookupWord

int Dictionary::partitionWords(int left, int right)
{
    string x = words[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (words[j] <= x)
        {
            i++;
            swap(words[i], words[j]);
        }
    }
    
    swap(words[i+1], words[right]);
    
    return (i+1);
} // end partition


void Dictionary::quicksortHelper(int left, int right)
{
    if (left < right)
    {
        int s = partitionWords(left, right);
        quicksortHelper(left, s - 1);
        quicksortHelper(s + 1, right);
    }
}

void Dictionary::quicksort(const string&filename)
{
    auto start = chrono::system_clock::now();

    if (!words.empty())
    {
        int right = words.size() - 1;
        quicksortHelper(0, right);
    }

    ofstream fout(filename);

    if (!fout)
    {
        throw fileOpenError(filename);
    }

    for (const string& word : words)
    {
        fout << word << '\n';
    }

    fout.close();

    auto end = chrono::system_clock::now();

   cout << "Quicksort runtime: "
              << chrono::duration_cast<chrono::milliseconds>(end - start)
                .count() <<" ms" << endl;
}

void Dictionary::heapsortWords(const string& filename)
{
    Heap<string> heap;
    heap.initializeMaxHeap(words);
    words = heap.heapsort();
}


ostream& operator<<(ostream& os, const Dictionary& dict)
// Overloaded output operator << to print the word list. writes the present
// words in respective dict to the respective os.
{
    // prints the current order of words in the vector
    for (int i = 0; i < dict.words.size(); i++)
    {
        os << dict.words[i] << " ";
    } // end for
    
    return os;
} // end operator<<