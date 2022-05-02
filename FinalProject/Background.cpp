/**
 * Definitions for background class
 * @author Caleb Fender & KC Etienne
 * HR: NONE
 */
#include <Vector2d.hpp>
#include <Thing.hpp>
#include <PolygonShape.hpp>

#include "Background.h"

using namespace vmi;

/**
 * Constructs a new background
 */
Background::Background() : Thing(Vector2d(),            // position
                                new PolygonShape(),  // sprite
                                2)                      // put in background
{
    // add points to the shape
    PolygonShape *p = dynamic_cast<PolygonShape*>(shape);

    p->addPoint(Vector2d(0, 0));
    p->addPoint(Vector2d(800, 0));
    p->addPoint(Vector2d(800, 400));
    p->addPoint(Vector2d(0, 400));
    p->setFill(Color::Blue);
}                        

/**
 * Deconstructs the background
 */
Background::~Background()
{
    delete shape;
}

/**
 * Does nothing, just need to inherit it
 * @param other whats colliding with background
 */
void Background::handleCollision(const Thing* other)
{
    // intentionally  blank
}