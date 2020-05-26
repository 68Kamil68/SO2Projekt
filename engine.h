#ifndef ENGINE_H
#define ENGINE_H
#include <tuple>
#include <vector>
#include "star.h"

class Engine {
    public:
        Engine();
        int GetTime();
        int GetPoints();
        void AddPoints(int points);
        void GenerateStar();
        std::vector<Star*> stars;

    private:
        int time;
        int points;

};
#endif