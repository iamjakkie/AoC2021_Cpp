#include "lanternfish.h"

Lanternfish::Lanternfish(){
    setDay(8);
}
Lanternfish::Lanternfish(int day){
    setDay(day);
}
std::optional<Lanternfish*> Lanternfish::moveTimer(){
    auto currDay = getDay()-1;
    setDay(currDay);
    if(currDay == 0){
        setDay(6);
        return new Lanternfish();
    }
    return {};
}