
#include <Game.hpp>
#include "DinosaurRunGame.h"

using namespace vmi;

/**
 * Constructs a new DinosaurRunGame object which is a VMIGameEngine Game and automatically starts the game
 */
DinosaurRunGame::DinosaurRunGame() : Game("Dino Run", 800, 600) {
    startLevel();
}

/**
 * Per-frame update of the game
 * @param dt time of the frame
 */
void DinosaurRunGame::update(double dt) {
    
}

/**
 * Checks to see if game is over
 * @return true if game is over
 * @return false if game is not over
 */
bool DinosaurRunGame::isOver() const {
    return done;
}

/**
 * Starts the game by creating everything
 */
void DinosaurRunGame::startLevel() {
    dino = new Dino();
}