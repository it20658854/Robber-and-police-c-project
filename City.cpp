#include "City.h"
#include <cstdlib>
#include <ctime>
#include <iostream> // Add this line

char City::grid[7][7];
Jewel* City::jewels[7][7];
int City::jewelCount = 0;

City::City() {
    // Initialize the city grid and jewels array
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            grid[i][j] = ' ';
            jewels[i][j] = nullptr;
        }
    }
}

void City::printCity() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void City::scatterJewels() {
    // Seed the random number generator
    std::srand(100);

    for (int i = 0; i < 30; ++i) {
        int x = std::rand() % 7;
        int y = std::rand() % 7;

        // Check if the cell is empty before placing a jewel
        if (grid[x][y] == ' ' && jewels[x][y] == nullptr) {
            grid[x][y] = 'J';
            jewels[x][y] = new Jewel(x, y);  // Create a new Jewel object at the specified position
            jewelCount++;
        } else {
            // If the cell is occupied, try again
            --i;
        }
    }
}

char City::getGridCell(int x, int y) {
    return grid[x][y];
}

int City::getJewelValue(int x, int y) {
    return jewels[x][y]->getValue();
}

void City::removeJewel(int x, int y) {
    grid[x][y] = ' ';
    delete jewels[x][y];  // Delete the Jewel object to avoid memory leaks
    jewels[x][y] = nullptr;
    jewelCount--;
}

int City::getJewelCount() {
    return jewelCount;
}

