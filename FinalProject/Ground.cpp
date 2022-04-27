/**
 * This file contains the definitions for the Ground class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <Thing.hpp>
#include <Vector2d.hpp>
#include <SpriteShape.hpp>
#include "Ground.h"

using namespace vmi;

/**
 * Constructs a new Ground object
 */
Ground::Ground() : Thing(Vector2d(0, 330), new SpriteShape("FinalProject/ground.png"))
{
}

/**
 * Deconstructs a ground object
 */
Ground::~Ground()
{
    delete shape;
}

/**
 * Handles collisions between Ground and other objects
 * @param other object the Ground is colliding with
 */
void Ground::handleCollision(const Thing *other)
{
    // intentionally left blank, Ground does not collide into anything
}