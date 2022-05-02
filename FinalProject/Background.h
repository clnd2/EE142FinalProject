/**
 * Header file for background
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <Thing.hpp>

/**
 * Background for our game
 */
class Background : public vmi::Thing
{
public:
    Background();
    ~Background();

    void handleCollision(const Thing* other);
};