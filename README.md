# EECE-2560-wordsearch
## Overview
Part A: The wordsearch program accepts a grid of words (e.g., [input15.txt](input15.txt)) and an unsorted dictionary of candidate words (e.g., [Dictionary.txt](Dictionary.txt)). A selection sort algorithm is used to output a sorted dictionary ([dictionary-sorted.txt](dictionary-sorted.txt)). The program then uses the `findMatches()` function to search the full grid from each letter in all 8 directions, wrapping where necessary to find candidate words. Candidate words are compared with the sorted dictionary using a binary search; any matches are output to [output.txt](output.txt) in the format:

| word | start point (i, j) | found index |
| --- | --- | --- | 
| north | (0, 2) | 1200 |

## Building and Running the Project

The [CMakeLists.txt](CMakeLists.txt) file will build the project. With CMake installed run

```
cmake -S . -B build
cmake --build build
```
This will configure CMake and build the project

To run the project
```
./build/wordsearch
```

The program will prompt for the name of the file with the word search grid, which must be entered by the user.