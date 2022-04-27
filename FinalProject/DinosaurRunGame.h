/**
 * This file is the header file for the DinosaurRunGame class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <Game.hpp>
#include "Dino.h"

/**
 * This class is our game based off of the Google Dinosaur Run game
 */
class DinosaurRunGame : public vmi::Game {
    public:
        // Constructor
        DinosaurRunGame();
        // frame update
        void update(double dt);
        // check if game is over
        bool isOver() const;
        // starts the level
        void startLevel();
    private:
        // if game is done
        bool done;
        // pointer to player
        Dino *dino;
};
