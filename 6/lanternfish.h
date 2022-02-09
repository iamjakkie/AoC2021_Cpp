#include <optional>

class Lanternfish{
    public:
     Lanternfish();
     Lanternfish(int day): _day(day) {};
     ~Lanternfish();
     std::optional<Lanternfish*> moveTimer();

    private:
     int _day;
     
};