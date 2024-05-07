#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "bloomfilter.h"

using namespace std;

int main(){

    BloomFilter<string, 10000, 3> filter;

//Using top 50 fruits in america
    ifstream inputFile("fruits.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            filter.insert(line);
        }
        inputFile.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }


//Searching for values
//Case Sensitive
    char choice;
    while(choice != 'N' && choice != 'n'){
        string guess;
        cout << "Guess - ";
        cin >> guess;
        cout << "Contains '" << guess << "'? - " << (filter.contains(guess) ? " Yes" : " No") << endl;
        cout << "(Y/N) Continue? ";
        cin >> choice;
    }

    return 0;
}