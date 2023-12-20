// Police.cpp
#include "Police.h"
#include "City.h"
#include "Robber.h"  // Include the Robber header
#include <cstdlib>

int Police::totalConfiscatedLoot = 0;

Police::Police(int id) {
    uniqueId = id;
    xCoordinate = std::rand() % 7;
    yCoordinate = std::rand() % 7;
    totalLootConfiscated = 0;
    totalRobbersCaught = 0;
}

void Police::arrest(Robber& robber) {
    // Arrest the robber and update statistics
    robber.setActiveStatus(false);  // Set the isActive status using the method
    totalRobbersCaught++;
    totalLootConfiscated += robber.getTotalLoot();

    // Update the city grid to reflect the arrest
    int x = robber.getXCoordinate();
    int y = robber.getYCoordinate();
    City::removeJewel(x, y);
}


void Police::move() {
    // Move the police in a random direction (similar to the ordinary robber)
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

    // Check for scenarios after moving (similar to the Robber::move())
}

int Police::getTotalLootConfiscated() const {
    return totalLootConfiscated;
}

int Police::getTotalRobbersCaught() const {
    return totalRobbersCaught;
}