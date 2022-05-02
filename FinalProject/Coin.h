/**
 * Header file for coin class
 * @author Caleb Fedner & KC Etienne
 * HR: NONE
 */
#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>

/**
 * Coin for our player to collect
 */
class Coin : public vmi::MovingThing
{
public:
    Coin(const vmi::Vector2d& _x);
    ~Coin();
    void handleCollision(const vmi::Thing *other);
};