/**
 * The header file for the Enemy class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <stdlib.h>

/**
 * Enemy for our dino
 */
class Enemy : vmi::MovingThing
{
public:
    // constructs an Enemy with parameters for position and what image to use
    Enemy(const vmi::Vector2d &_x, const std::string _image);
    // deconstructs an Enemy
    ~Enemy();
    // inherited function to handle collisions
    void handleCollision(const vmi::Thing* other);
    // creates enemies
    static void createEnemies();
};