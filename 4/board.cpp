#include "board.h"

Board::Board(const std::array<std::array<int, 5>, 5> &input)
{
    _bd = input;
    int a_ind = 0;
    int b_ind = 0;
    for (const auto &arr : input)
    {
        for (const auto &num : arr)
        {
            _nums.insert(std::make_pair(num, Pos{a_ind, b_ind}));
            _unmarked+=num;
            a_ind++;
        }
        b_ind++;
        a_ind = 0;
    }
    for (auto i = 0; i < 5; i++)
    {
        _colsHit[i] = 0;
        _rowsHit[i] = 0;
    }
}

bool Board::checkNumber(const int &num)
{
    auto it = _nums.find(num);
    if (it != _nums.end())
    {
        _unmarked-=num;
        _marked+=num;
        Pos p = it->second;
        bool inCols = check(_colsHit, p.Y);
        bool inRows = check(_rowsHit, p.X);
        return inCols || inRows;
    }
}

bool Board::check(std::unordered_map<int, int>& direction, const int &num)
{
    auto it = direction.find(num);
    if (it != direction.end())
    {
        it->second++;
        if (it->second == 5)
        {
            std::cout << "Unmarked:" << _unmarked << std::endl;
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Board& bd)
{
    os << "===BOARD===\n";
    for (auto arr : bd._bd){
        for (auto num : arr){
            os << std::to_string(num) << " ";
        }
        os << std::endl;
    }
    return os;
}