/**
 * @file DinosaurRunGame.h
 * @author Caleb Fender & KC Etienne
 * 
 */
#pragma once

#include <Game.hpp>
#include "Dino.h"

class DinosaurRunGame : public vmi::Game {
    public:
        DinosaurRunGame();

        void update(double dt);
        bool isOver() const;
        void startLevel();
    private:
        bool done;
        Dino *dino;
};
