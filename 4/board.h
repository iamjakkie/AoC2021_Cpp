#include <array>
#include <unordered_map>
#include <ostream>
#include <iostream>

struct Pos
{
    int X;
    int Y;
};


class Board {
    public:
     Board(const std::array<std::array<int, 5>, 5>& board, const int& id);
    //  ~Board();
     bool checkNumber(const int& num);
     friend std::ostream& operator<<(std::ostream& os, const Board& bd);
     bool operator==(const Board& bd);
     const int getId();
     const int getUnmarked();
     

    private:
     bool check(std::unordered_map<int, int>& direction, const int& num);
     
     int _num;
     std::unordered_map<int, int> _rowsHit;
     std::unordered_map<int, int> _colsHit;
     std::unordered_map<int, Pos> _nums;
     std::array<std::array<int, 5>, 5> _bd;
     int _unmarked = 0;
     int _marked = 0;

};

std::ostream& operator<<(std::ostream& os, const Board& bd);