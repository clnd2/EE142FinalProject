
#include <Graphics.hpp>
#include <SpriteShape.hpp>
#include <MovingThing.hpp>
#include <Thing.hpp>
#include <Vector2d.hpp>
#include "Dino.h"

using namespace vmi;
/**
 * Constructs a new dino object
 */
Dino::Dino() : MovingThing(Vector2d(375, 275), Vector2d(), Vector2d(0, 980), new SpriteShape("FinalProject/dino.png")) {

}

Dino::~Dino() {
    delete shape;
}

void handleCollision(const Thing* other) {
    
}