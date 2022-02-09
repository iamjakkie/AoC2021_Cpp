#include <optional>

class Lanternfish{
    public:
     Lanternfish();
     Lanternfish(int day): _day(day) {};
     ~Lanternfish();
     std::optional<Lanternfish*> moveTimer();
     int getDay();
     void setDay(int day);

    private:
     int _day;
     
};