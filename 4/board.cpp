

#include "board.h"

Board::Board(const std::array<std::array<int, 5>, 5>& input){
    int a_ind, b_ind = 0;
    for(const auto& arr: input){
        for(const auto& num: arr){
            _cols[b_ind] = num;
            _rows[a_ind] = num;
            _nums.insert(std::make_pair(num, Pos{a_ind, b_ind}));
        }
    }
}