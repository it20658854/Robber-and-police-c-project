// Police.h
class Robber;
#ifndef POLICE_H
#define POLICE_H

#include "Robber.h"

class Police {
private:
    static int totalConfiscatedLoot;  // Static member variable to store the total worth of loot confiscated by all police
    int uniqueId;  // Unique ID for the police
    int xCoordinate;  // Current X-coordinate for the police's position in the city grid
    int yCoordinate;  // Current Y-coordinate for the police's position in the city grid
    int totalLootConfiscated;  // Total worth of loot confiscated by this police officer
    int totalRobbersCaught;  // Total number of robbers caught by this police officer

    // Static arrays to keep track of police officers' positions
    static int totalPolice;  // Total number of police officers
    static Police* police;   // Array of police officers

public:
    Police(int id);  // Constructor to initialize the police officer
    void arrest(Robber& robber);  // Function to arrest a robber and update statistics
    void move();  // Function to move the police officer in a specific direction
    int getTotalLootConfiscated() const;  // Function to get the total worth of loot confiscated by this police
    int getTotalRobbersCaught() const;  // Function to get the total number of robbers caught by this police
    static Police* getPoliceArray();

    // Static functions to get police officers' positions
    static int getPoliceXCoordinate(int index);
    static int getPoliceYCoordinate(int index);
    static int getTotalPolice();
    void checkForArrest(int x, int y);
     void checkForJewel(int x, int y);
};

#endif
