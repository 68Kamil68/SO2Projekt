#include <tuple>

class Star {
    public:
        Star(int x, bool isBonus);
        std::tuple<int, int> GetCoords();
        bool IsBonus();
        void Move();

    private:
        int x, y;
        bool isBonus;

};