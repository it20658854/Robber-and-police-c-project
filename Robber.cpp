#include "Robber.h"
#include "City.h"
#include <cstdlib>
#include <cmath>

int Robber::totalLoot = 0;

Robber::Robber(int id, bool greedy) {
    uniqueId = id;
    xCoordinate = std::rand() % 7;
    yCoordinate = std::rand() % 7;
    lootCount = 0;
    isActive = true;
    isGreedy = greedy;
    consecutiveMoves = 0;
}

void Robber::pickUpLoot() {
    // Check if the bag is not full
    if (lootCount < 10) {
        // Access the city grid to check for loot at the robber's current position
        if (City::getGridCell(xCoordinate, yCoordinate) == 'J') {
            // If loot is found, pick it up
            lootBag[lootCount++] = City::getJewelValue(xCoordinate, yCoordinate);
            City::removeJewel(xCoordinate, yCoordinate);  // Remove the jewel from the city grid
        }
    }
}

void Robber::move() {
    // Check if the robber is still active
    if (isActive) {
        // Generate a random direction (0 to 7)
        int direction = std::rand() % 8;

        // Determine the new coordinates based on the direction
        switch (direction) {
            case 0:  // NW
                xCoordinate = std::max(0, xCoordinate - 1);
                yCoordinate = std::max(0, yCoordinate - 1);
                break;
            case 1:  // N
                xCoordinate = std::max(0, xCoordinate - 1);
                break;
            case 2:  // NE
                xCoordinate = std::max(0, xCoordinate - 1);
                yCoordinate = std::min(6, yCoordinate + 1);
                break;
            case 3:  // W
                yCoordinate = std::max(0, yCoordinate - 1);
                break;
            case 4:  // E
                yCoordinate = std::min(6, yCoordinate + 1);
                break;
            case 5:  // SW
                xCoordinate = std::min(6, xCoordinate + 1);
                yCoordinate = std::max(0, yCoordinate - 1);
                break;
            case 6:  // S
                xCoordinate = std::min(6, xCoordinate + 1);
                break;
            case 7:  // SE
                xCoordinate = std::min(6, xCoordinate + 1);
                yCoordinate = std::min(6, yCoordinate + 1);
                break;
        }

        // Check for various scenarios after moving
        // (You need to implement these scenarios as described in the project details)
    }
}

void Robber::printStatus() {
    std::cout << "Robber ID: " << uniqueId << std::endl;
    std::cout << "Coordinates: (" << xCoordinate << ", " << yCoordinate << ")" << std::endl;
    std::cout << "Loot Count: " << lootCount << std::endl;

    // If loot count is greater than 0, print the loot details
    if (lootCount > 0) {
        std::cout << "Loot Details:" << std::endl;
        for (int i = 0; i < lootCount; ++i) {
            std::cout << "  Loot " << (i + 1) << ": $" << lootBag[i] << std::endl;
        }
    }
    
    std::cout << "Total Loot Worth: $" << getTotalLoot() << std::endl;
    std::cout << "Active: " << (isActive ? "Yes" : "No") << std::endl;
    std::cout << "Type: " << (isGreedy ? "Greedy" : "Ordinary") << std::endl;
}
int Robber::getTotalLoot() {
    return totalLoot;
}

void Robber::setActiveStatus(bool status) {
    isActive = status;
}
int Robber::getXCoordinate() const {
    return xCoordinate;
}

int Robber::getYCoordinate() const {
    return yCoordinate;
}