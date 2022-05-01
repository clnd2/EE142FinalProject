/**
 * @file Enemy.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Enemy.h"
#include <Thing.hpp>
#include <MovingThing.hpp>
#include <Vector2d.hpp>
#include <Graphics.hpp>
#include <stdlib.h>
#include <SpriteShape.hpp>
#include "Wall.h"
#include <Timer.hpp>

using namespace vmi;

/**
 * Constructs a new Enemy object
 * @param _x initial position of the Enemy
 * @param _image image to use for enemy
 */
Enemy::Enemy(const Vector2d &_x, std::string _image) : MovingThing(_x, Vector2d(-400, 0), Vector2d(), new SpriteShape(_image))
{
    // intentionally blank
}

/**
 * Deconstructs an Enemy object
 */
Enemy::~Enemy()
{
    delete shape;
}

/**
 * Handles collisions of Enemy with other objects
 * @param other object Enemy is colliding with
 */
void Enemy::handleCollision(const Thing* other)
{
    // Enemy dies if hits a Wall
    if (typeid(*other) == typeid(Wall))
    {
        die();
    }
}

void Enemy::createEnemies() {
    // randomly select low or high
    int location = rand() % 2;
    // create high enemy
    if (location == 1) {
        new Enemy(Vector2d(900, 50), "FinalProject/highEnemy.png");
    }
    // create low enemy
    else if (location == 0) {
        new Enemy(Vector2d(900, 268), "FinalProject/lowEnemy.png");
    }

    // now set up to create the next enemies after a delay
    int delayTime = rand() % 4;         // between 0 and 4 seconds
    Timer::createTimer(delayTime, []() { Enemy::createEnemies(); });
}