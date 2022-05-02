/**
 * This file defines the Dino class
 * @author Caleb Fender & KC Etienne
 * HR: Dino.png taken from PixilArt.com
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
#include "Enemy.h"
#include <sstream>
#include "Coin.h"
#include <Text.hpp>
#include <Color.hpp>

using namespace vmi;

unsigned int Dino::highscore = 0;

/**
 * Constructs a new dino object
 */
Dino::Dino() : MovingThing(Vector2d(100, 275), Vector2d(), Vector2d(0, 1000), new SpriteShape("FinalProject/dino.png"), 0), score(0)
{
    // set up the text display of the score
    scoreText.setText("0");
    scoreText.setCharacterSize(50);
    scoreText.setPosition(Vector2d(650, 25));
    scoreText.setFill(Color::White);

    // get highscore and set up text display of the highscore
    std::stringstream ss;
    ss << highscore;
    highText.setText(ss.str());
    highText.setCharacterSize(50);
    highText.setPosition(Vector2d(725, 25));
    highText.setFill(Color::White);
}

/**
 * Deconstruct the Dino object
 */
Dino::~Dino()
{
    delete shape;
}

/**
 * Handle collisions of the Dino object with other objects
 * @param other object colliding with Dino
 */
void Dino::handleCollision(const Thing *other)
{
    // check if colliding with the ground
    if (typeid(*other) == typeid(Ground))
    {
        v = Vector2d();
        x.setY(256);
    }
    // die if colliding with enemy
    else if (typeid(*other) == typeid(Enemy))
    {
        die();
    }
    // score a point if colliding with a coin
    else if (typeid(*other) == typeid(Coin))
    {
        scorePoint();
    }
}

/**
 * Makes the dino move when the right keys are pressed
 * @param dt
 */
void Dino::move(double dt)
{
    // check if Up or Space key is pressed and if dino is touching the ground
    if ((Game::isKeyPressed(Key::Space) || Game::isKeyPressed(Key::Up)) && x.getY() == 256)
    {
        // constant velocity upwards
        v.setY(-500);
    }

    MovingThing::move(dt);
}

/**
 * Update the score when a player scores a point
 */
void Dino::scorePoint()
{
    score++;

    // update the display
    std::stringstream ss;
    ss << score;
    scoreText.setText(ss.str());

    if (score > highscore) {
        setHighscore(score);
    }
}

/**
 * Getter function for score
 * @return int the current score
 */
int Dino::getScore() const
{
    return score;
}

/**
 * Sets a new highscore
 * @param _score the new highscore
 */
void Dino::setHighscore(int _score)
{
    // set new highscore
    highscore = _score;

    // update the display
    std::stringstream ss;
    ss << highscore;
    highText.setText(ss.str());
}

/**
 * Draws the shape
 * @param target 
 * @param states 
 */
void Dino::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the dino
    Thing::draw(target, states);

    // draw the score
    scoreText.draw(target, states);
    highText.draw(target, states);
}