/**
 * Header file for coin class
 * @author Caleb Fedner & KC Etienne
 * HR: NONE
 */
#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>

/**
 * Coin for our player to collect
 */
class Coin : public vmi::MovingThing
{
public:
    Coin();
    ~Coin();
    void handleCollision(const vmi::Thing *other);
};