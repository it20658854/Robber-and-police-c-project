// Jewel.cpp
#include "Jewel.h"
#include <cmath>

Jewel::Jewel(int x, int y) {
    xCoordinate = x;
    yCoordinate = y;
    // Calculate the value of the jewel based on grid coordinates
    value = static_cast<int>(std::pow(x, 2) + std::pow(y, 2));
}

int Jewel::getValue() const {
    return value;
}

int Jewel::getXCoordinate() const {
    return xCoordinate;
}

int Jewel::getYCoordinate() const {
    return yCoordinate;
}
