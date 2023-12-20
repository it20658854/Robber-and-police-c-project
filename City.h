// City.h
#ifndef CITY_H
#define CITY_H

#include "Jewel.h"

class City {
private:
    static char grid[7][7];  // 2D array representing the city grid
    static Jewel* jewels[7][7]; // 2D array of pointers to Jewel objects
    static int jewelCount;   // Current count of jewels in the city grid
    static const int MAX_ROBBERS = 10;  // Define MAX_ROBBERS here

public:
    City();  // Constructor to initialize the city
    void printCity();  // Function to print the current state of the city
    void scatterJewels();  // Function to scatter jewels in the city
    static char getGridCell(int x, int y);  // Static function to get the value of a cell in the city grid
    static int getJewelValue(int x, int y);  // Static function to get the value of a jewel at a specific position
    static void removeJewel(int x, int y);  // Static function to remove a jewel from the city grid
    static int getJewelCount();  // Static function to get the total count of jewels

    static void checkForJewel(int x, int y);
};

#endif
