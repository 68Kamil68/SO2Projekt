#include <tuple>

class Engine {
    public:
        Engine();
        int GetTime();
        int GetPoints();
        void AddPoints(int points);

    private:
        int time;
        int points;

};