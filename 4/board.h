#include <array>
#include <unordered_map>

struct Pos
{
    int X;
    int Y;
};


class Board {
    protected:
     Board(const std::array<std::array<int, 5>, 5>& input);
     ~Board();
     bool checkNumber(const int& num);

    private:
     bool checkRows();
     bool checkCols();
     void mark(const int& num);
     void split();

     std::array<int, 5> _cols;
     std::array<int, 5> _rows;
     std::unordered_map<int, Pos> _nums;
};