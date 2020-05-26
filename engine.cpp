#include "engine.h"

Engine::Engine() {

}

void Engine::GenerateStar() {
    Star *star = new Star(200, false, 1, 1);
    this->stars.push_back(star);
}