#include <tuple>

class Player {
    public:
        Player();
        std::tuple<int, int> GetCoords();
        void Move();

    private:
        int x, y;
        
};