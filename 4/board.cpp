#include "board.h"

Board::Board(const std::array<std::array<int, 5>, 5> &input, const int& id)
{
    _num = id;
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
            return true;
        }
    }
    return false;
}

const int Board::getUnmarked(){
    return _unmarked;
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

const int Board::getId(){
    return _num;
}

// bool Board::operator==(const Board& otherBoard) const
//   {
//     if (this->_bd == otherBoard._bd) return true;
//     else return false;
//   }

//   struct HashFunction
//   {
//     size_t operator()(const Board& bd) const
//     {
//       size_t xHash = std::hash<std::array<std::array<int,5>,5>()(bd._bd);
//       return xHash;
//     }
//   };