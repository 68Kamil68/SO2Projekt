#include "engine.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <unistd.h>


Engine::Engine() {

}

void Engine::GenerateStar() {
    int random_y = rand() % 88 + 1;
    int random_bonus = rand() % 100;
    bool bonus = false;
    if (random_bonus > 90) {
        bonus = true;
    }
    Star *star = new Star(random_y, bonus, gamespeed, 1);
    this->stars.push_back(star);
    usleep(600000/((time+1)/10));
}

void Engine::AddPoints(int p){
    points+=p;
}

int Engine::GetPoints(){
    return points;
}

void Engine::SetPoints(int x){
    points=x;
}

int Engine::GetTime(){
    return time;
}

void Engine::SetTime(int t){
    time=t;
}