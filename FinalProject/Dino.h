/**
 * This is the header file for the dino class which is our player
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#pragma once

#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Text.hpp>
#include <Graphics.hpp>
/**
 * The player
 */
class Dino : public vmi::MovingThing
{
public:
    // Default Constructor
    Dino();
    // Destructor
    ~Dino();
    // inherited function to handle collisions
    void handleCollision(const vmi::Thing *other);
    // inherited function to move the player
    void move(double dt);
    // get score
    int getScore() const;
    // player's highest score
    static unsigned int highscore;
    // override draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    // player's score
    unsigned int score;
    // score text
    vmi::Text scoreText;
    // score a point
    void scorePoint();
    // updates high score
    void setHighscore(int _score);
    // highscore text
    vmi::Text highText;
};