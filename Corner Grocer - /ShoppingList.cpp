#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

#include "ShoppingList.h"

/**
 * Default Constructor for ShoppingList Class
*/
ShoppingList::ShoppingList() {
    NUM_MENU_OPTIONS = 4;
    MENU_WIDTH = 40;
}

/**
 * Creates a string of a specific length with a specific character. 
 * 
 * @param int number of repetitions
 * @param char character to be repeated
 * @return string of specified characters
*/
string ShoppingList::nCharString(size_t n, char c) {
    string tempString = "";
    for (int i = 0; i < n; i++) {
        tempString += c;
    }
    return tempString;
}

/**
 * Prints the menu with formatting
*/
void ShoppingList::printMenu() {
    cout << nCharString(MENU_WIDTH, '*') << endl;

    for (int i = 0; i < NUM_MENU_OPTIONS; i++) {
        int spaces = MENU_WIDTH - MENU_STRINGS[i].length() - 7;
        cout << "* " << i + 1 << " - " << MENU_STRINGS[i];
        cout << nCharString(spaces, ' ');
        cout << "*" << endl;
        if (i != (NUM_MENU_OPTIONS - 1)) {
            cout << endl;
        }
    }
    cout << nCharString(MENU_WIDTH, '*') << endl;
}

/**
 * Gets the user's input when choosing from the menu. Makes sure that it's a valid option and loops if not.
 * 
 * @return returns the user's input when valid. 
*/
int ShoppingList::getMenuChoice() {
    int maxChoice = NUM_MENU_OPTIONS;
    bool validChoice = false;
    int userInput = 0;
    do {
        cin >> userInput;
        if ((userInput >= 1) && (userInput <= maxChoice)) {
            validChoice = true;
            return userInput;
        }
        cout << "Enter a valid menu number. (1 - " << maxChoice << ")" << endl;
    } while (validChoice == false);
    return 0;
}


/**
 * Reads a specified text file and puts the data into a map
 * 
 * @param string name/filepath for the text file
 * @param string name/filepath for the backup file
*/
void ShoppingList::parseTextFile(string filePath, string backupFilePath) {

    ifstream MyFile(filePath);

    while (getline (MyFile, myText)) {
        shoppingData[myText] += 1;
    }
    MyFile.close();

    ofstream DataBackUp(backupFilePath);
    cout << "I should create a file." << endl;

    for (const auto& elem : shoppingData) {
        DataBackUp << elem.first << " " << elem.second << endl;
    }
    DataBackUp.close();

}

/**
 * Looks up the frequency/value of a item in a map given a key
*/
void ShoppingList::frequencyLookUp() {
    string itemLookUp;
    cout << "Enter an item to look up:" << endl;
    cin >> itemLookUp;
    itemLookUp[0] = toupper(itemLookUp[0]);
    cout << "There were " << shoppingData[itemLookUp] << " " << itemLookUp << " bought." << endl;

}

/**
 * Prints the keys and values of  map (Frequency Report)
*/
void ShoppingList::frequencyReport() {
    string header = "FREQUENCY REPORT";
    cout << endl;
    cout << header << endl;
    cout << nCharString(MENU_WIDTH, '-') << endl;
    for (const auto& elem : shoppingData) {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl << endl;
}

/**
 * Prints a histogram of the frequencies from a map
*/
void ShoppingList::frequencyHistogram() {
    string header = "FREQUENCY HISTOGRAM";
    cout << endl;
    cout << nCharString((MENU_WIDTH - header.length()) / 2, ' ') << header << endl;
    cout << nCharString(MENU_WIDTH, '-') << endl;
    for (const auto& elem : shoppingData) {
        cout << setw(MENU_WIDTH/2) << right;
        cout << elem.first << " ";
        cout << left << nCharString(elem.second, '*') << endl;
    }
    cout << endl << endl;
}

