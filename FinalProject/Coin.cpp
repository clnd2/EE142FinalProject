/**
 * Definitions for the coin class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include "Wall.h"
#include "Dino.h"
#include "Coin.h"

using namespace vmi;

/**
 * Constructs a new coin
 * @param _x position of coin
 */
Coin::Coin(const Vector2d& _x) : MovingThing(_x, Vector2d(-400, 0), Vector2d(), new SpriteShape("FinalProject/Coin.png")) {
    // intentionally blank
}

/**
 * Deconstructs a coin
 */
Coin::~Coin() {
    delete shape;
}

/**
 * Handle collisions with coin and other objects
 * @param other object colliding with coin
 */
void Coin::handleCollision(const Thing* other) {
    // die if hit wall or dino
    if (typeid(*other) == typeid(Wall) || typeid(*other) == typeid(Dino)) {
        die();
    }
}