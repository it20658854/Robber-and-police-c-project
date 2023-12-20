// Jewel.h
#ifndef JEWEL_H
#define JEWEL_H

class Jewel {
private:
    int value;  // The value (or worth) of the jewel
    int xCoordinate;  // X-coordinate of the jewel in the city grid
    int yCoordinate;  // Y-coordinate of the jewel in the city grid

public:
    Jewel(int x, int y);  // Constructor to initialize the jewel at a given position
    int getValue() const;  // Getter for the value of the jewel
    int getXCoordinate() const;  // Getter for the X-coordinate of the jewel
    int getYCoordinate() const;  // Getter for the Y-coordinate of the jewel
};

#endif
