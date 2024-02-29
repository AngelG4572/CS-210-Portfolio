#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

class ShoppingList {
    public:
        ShoppingList();
        string nCharString(size_t n, char c);
        void printMenu();
        int getMenuChoice();
        void parseTextFile(string filePath, string backupFilePath);
        void frequencyLookUp();
        void frequencyReport();
        void frequencyHistogram();
    private:
        int NUM_MENU_OPTIONS;
        string MENU_STRINGS[4] = {"Frequency Look-Up", "All Items Frequency Report", "All Items Frequency Histogram", "Exit Program"};
        int MENU_WIDTH;
        map<string, int> shoppingData;
        string myText;

};

#endif