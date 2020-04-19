#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "GameStateManager.h"

int main() {
    GameStateManager gsm;

    if (!gsm.printMainMenu()) { // Checks if false to see if user has failed initialization or exits
        return 0; // Stops the game
    }

    while (gsm.getEventManager().getCurrentDay() <= 6) {
    //Day 1
        if(!gsm.playDay()){ // Checks if false to see if user has died

            return 0; // Stops the game
        }
    }
    gsm.printEnd();
    return 0;
}
