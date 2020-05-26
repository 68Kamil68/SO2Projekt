#include "engine.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <unistd.h>


Engine::Engine() {

}

void Engine::GenerateStar() {
    int random_y = rand() % 90 + 1;
    int random_bonus = rand() % 100;
    bool bonus = false;
    if (random_bonus > 90) {
        bonus = true;
    }
    Star *star = new Star(random_y, bonus, gamespeed, 1);
    this->stars.push_back(star);
    sleep(1);
}