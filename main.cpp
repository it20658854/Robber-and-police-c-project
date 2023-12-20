#include <iostream>
#include <thread>
#include <chrono>
#include "City.h"
#include "Jewel.h"
#include "Robber.h"
#include "Police.h"
using namespace std;

int main() {
    // Initialize the city and scatter jewels
    City city;
    city.scatterJewels();
    city.printCity();

    // Create police officers and robbers
    Police police1(1);
    Police police2(2);
    Robber robber1(1, true);  // Greedy robber
    Robber robber2(2, false); // Ordinary robber

    // Simulation loop
    for (int turn = 1; turn <= 50; ++turn) {
        // Robbers move first
        robber1.move();
        robber2.move();

        // Police move next
        police1.move();
        police2.move();

        // Print city state after each turn
        city.printCity();

        // Print robber and police status
        std::cout << "Turn " << turn << ":\n";
        robber1.printStatus();
        robber2.printStatus();
        std::cout << "Total Loot Confiscated by Police: $" << police1.getTotalLootConfiscated() + police2.getTotalLootConfiscated() << "\n\n";

        // Check for termination conditions
        if (police1.getTotalRobbersCaught() > 0 || police2.getTotalRobbersCaught() > 0) {
            std::cout << "Police caught a robber! Simulation terminated.\n";
            break;
        }

        if (robber1.getTotalLoot() >= 50 || robber2.getTotalLoot() >= 50) {
            std::cout << "A robber collected enough loot! Simulation terminated.\n";
            break;
        }
        
    }

    // Print final summary
    std::cout << "Summary of the chase:\n";
    std::cout << "Total Loot Confiscated by Police: $" << police1.getTotalLootConfiscated() + police2.getTotalLootConfiscated() << "\n";
    std::cout << "Total Robbers Caught: " << police1.getTotalRobbersCaught() + police2.getTotalRobbersCaught() << "\n";
    std::cout << "Total Loot Collected by Robbers: $" << robber1.getTotalLoot() + robber2.getTotalLoot() << "\n";
    std::cout << "The robbers win the chase because maximum turns (50) have been reached\n";

    
    return 0;
}
