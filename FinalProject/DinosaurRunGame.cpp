/**
 * File for our DinosaurRunGame class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <Game.hpp>
#include "DinosaurRunGame.h"
#include "Ground.h"
#include "Dino.h"
#include "Enemy.h"
#include "Wall.h"

using namespace vmi;

/**
 * Constructs a new DinosaurRunGame object which is a VMIGameEngine Game and automatically starts the game
 */
DinosaurRunGame::DinosaurRunGame() : Game("Dino Run", 800, 400)
{
    startLevel();
}

/**
 * Per-frame update of the game
 * @param dt time of the frame
 */
void DinosaurRunGame::update(double dt)
{
    // check if bird is still alive
    if (!dino->isAlive()) {
        Key response;

        // display message to user
        do {
            response = Game::createMessage("Play again (Y/N)?",
                            Vector2d(200, 200), 60, Color::Yellow
            );
        } while (response != Key::Y && response != Key::N);

        // do we play again?
        if (response == Key::Y) {
            // first, cancel all active timers
            Timer::cancelAllTimers();

            // next, kill all game characters so we can re-start
            Thing::killAllThings();

            // finally, restart the level
            startLevel();
        }

        else {
            // don't play again
            done = true;
        }
    }
}

/**
 * Checks to see if game is over
 * @return true if game is over
 * @return false if game is not over
 */
bool DinosaurRunGame::isOver() const
{
    return done;
}

/**
 * Starts the game by creating everything needed
 */
void DinosaurRunGame::startLevel()
{
    // create game objects
    new Ground();
    new Wall();

    // create our player
    dino = new Dino();

    // starts creating enemies
    Enemy::createEnemies();
}