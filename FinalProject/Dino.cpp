/**
 * This file defines the Dino class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <Graphics.hpp>
#include <SpriteShape.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <Keyboard.hpp>
#include <Game.hpp>
#include "Ground.h"
#include "Dino.h"

using namespace vmi;

/**
 * Constructs a new dino object
 */
Dino::Dino() : MovingThing(Vector2d(375, 275), Vector2d(), Vector2d(0, 980), new SpriteShape("FinalProject/dino.png"), 0)
{
    //
}

Dino::~Dino()
{
    delete shape;
}

void Dino::handleCollision(const Thing *other)
{
    // check if colliding with the ground
    if (typeid(*other) == typeid(Ground)) {
        v = Vector2d();
        x.setY(200);
    }
}

/**
 * 
 * @param dt 
 */
void Dino::move(double dt) {
    if (Game::isKeyPressed(Key::Space)) {
        // constant velocity upwards
        v.setY(-200);
    }

    MovingThing::move(dt);
}