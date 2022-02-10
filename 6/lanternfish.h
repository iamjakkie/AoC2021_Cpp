#include <experimental/optional>

class Lanternfish{
    public:
     Lanternfish();
     Lanternfish(int day): _day(day) {};
     bool moveTimer();
     int getDay();
     void setDay(int day);

    private:
     int _day;
     
};