/**
 * File Header for Wall Class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <Thing.hpp>

/**
 * Wall used to kill enemies off screen that the player avoids
 */
class Wall : public vmi::Thing
{
public:
    // constructor
    Wall();
    // deconstructor
    ~Wall();
    // inherited function
    void handleCollision(const vmi::Thing *other);
};