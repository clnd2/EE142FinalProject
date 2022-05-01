/**
 * File for definitions of Wall class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <Vector2d.hpp>
#include <PolygonShape.hpp>
#include <Color.hpp>

#include "Wall.h"

using namespace vmi;

/**
 * Constructs a new Wall object off-screen
 */
Wall::Wall() : Thing(Vector2d(-50, 0), new PolygonShape())
{
    // add points to the shape
    PolygonShape *p = dynamic_cast<PolygonShape*>(shape);

    p->addPoint(Vector2d(0, 0));
    p->addPoint(Vector2d(1, 0));
    p->addPoint(Vector2d(1, 400));
    p->addPoint(Vector2d(0, 400));
    p->setFill(Color::Transparent);
}

/**
 * Deconstructs a Wall object
 */
Wall::~Wall()
{
    delete shape;
}

/**
 * Handles collisions between Walls and other objects
 * @param other object Wall is colliding with
 */
void Wall::handleCollision(const Thing* other)
{
    // ignore collisions
}