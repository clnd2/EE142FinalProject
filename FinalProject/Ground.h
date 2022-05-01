/**
 * This is the header file for the Ground class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <Thing.hpp>
/**
 * The ground the player runs on
 */
class Ground : public vmi::Thing
{
public:
    // default constructor
    Ground();
    // deconstructor
    ~Ground();
    // inherited function to handle collisions with other objects
    void handleCollision(const vmi::Thing *other);
};