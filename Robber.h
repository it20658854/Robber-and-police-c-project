// Robber.h
#ifndef ROBBER_H
#define ROBBER_H

#include <iostream>

class Robber {
private:
    static int totalLoot;  // Static member variable to store the total worth of loot collected by all robbers
    int uniqueId;  // Unique ID for the robber
    int xCoordinate;  // Current X-coordinate for the robber's position in the city grid
    int yCoordinate;  // Current Y-coordinate for the robber's position in the city grid
    char lootBag[10];  // Array to hold the loot (jewels)
    int lootCount;  // Current count of loot in the bag
    bool isActive;  // Variable indicating whether the robber is still active
    bool isGreedy;  // Variable representing the type of the robber: ordinary or greedy
    int consecutiveMoves;  // Count of consecutive moves for greedy robbers
    
public:
    Robber(int id, bool greedy);  // Constructor to initialize the robber
    void pickUpLoot();  // Function to pick up loot and insert it into the robber's bag
    void move();  // Function to move the robber in a specific direction
    void printStatus();  // Function to print the current status of the robber
    static int getTotalLoot();  // Static function to get the total worth of loot collected by all robbers

    // Public method to set the isActive status
    void setActiveStatus(bool status);
    int getXCoordinate() const;
    int getYCoordinate() const;
    void collectLoot(int lootValue) {
        // Update loot count and store loot in the loot bag
        lootCount++;
        lootBag[lootCount - 1] = lootValue;
    }
};

#endif

