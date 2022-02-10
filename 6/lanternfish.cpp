#include "lanternfish.h"

Lanternfish::Lanternfish(){
    setDay(8);
}
bool Lanternfish::moveTimer(){
    auto currDay = getDay();
    if(currDay == 0){
        setDay(6);
        return true;
    }
    currDay--;
    setDay(currDay);
    return false;
}
void Lanternfish::setDay(int day){
    _day = day;
}
int Lanternfish::getDay(){
    return _day;
}