#ifndef ENGINE_H
#define ENGINE_H
#include <tuple>
#include <vector>
#include "star.h"

class Engine {
    public:
        Engine();
        int GetTime();
        void SetTime(int t);
        int GetPoints();
        void SetPoints(int x);
        void AddPoints(int points);
        void GenerateStar();
        std::vector<Star*> stars;
        int gamespeed;

    private:
        int time=0;
        int points=0;

};
#endif