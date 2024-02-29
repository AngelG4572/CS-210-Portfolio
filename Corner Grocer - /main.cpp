/*
Angelina Solis
CS 210
Project 3 - Grocery Item Tracking
February 26th 2024
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include "ShoppingList.h"

using namespace std;

int main() {
    const string FILE_NAME = "CS210_Project_Three_Input_File.txt";
    const string BACKUP_FILE_NAME = "frequency.dat";
    ShoppingList CornerGrocer;
    CornerGrocer.parseTextFile(FILE_NAME, BACKUP_FILE_NAME);
    CornerGrocer.printMenu();
    int menuOption = 0;
    do {
        menuOption = CornerGrocer.getMenuChoice();
        switch (menuOption) {
            case 1:
                CornerGrocer.frequencyLookUp();
                CornerGrocer.printMenu();
                break;
            case 2:
                CornerGrocer.frequencyReport();
                CornerGrocer.printMenu();
                break;
            case 3:
                CornerGrocer.frequencyHistogram();
                CornerGrocer.printMenu();
                break;
            default:
                cout << "Goodbye." << endl;
                break;
        }
    } while (menuOption != 4);

    return 0;
}
