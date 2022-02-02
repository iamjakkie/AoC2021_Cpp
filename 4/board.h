#include <array>
#include <unordered_map>
#include <ostream>

struct Pos
{
    int X;
    int Y;
};


class Board {
    public:
     Board(const std::array<std::array<int, 5>, 5>& board);
    //  ~Board();
     bool checkNumber(const int& num);
     friend std::ostream& operator<<(std::ostream& os, const Board& bd);
     

    private:
     bool check(std::unordered_map<int, int>& direction, const int& num);

     std::unordered_map<int, int> _rowsHit;
     std::unordered_map<int, int> _colsHit;
     std::unordered_map<int, Pos> _nums;
     std::array<std::array<int, 5>, 5> _bd;
};

std::ostream& operator<<(std::ostream& os, const Board& bd);