#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>

#define SIZE = 5

int main(){
    std::ifstream file("input.txt");
    std::string str, guesses;
    std::vector<std::array<std::array<int, 5>, 5>> boards;

    std::getline(file, guesses);

    std::cout << guesses << std::endl;
    int g_ind, ind = 0;
    std::array<std::array<int, 5>, 5> board;
    while(std::getline(file, str)){
        std::array<int, 5> arr;
        if(str != ""){
            std::istringstream iss(str);
            std::string s_num;
            while(std::getline(iss, s_num, ' ')){
                if(s_num != ""){
                    arr[ind++] = std::stoi(s_num);
                }
            }
            board[g_ind++] = arr;
            // arr[ind++] = 
            // std::cout << "Line" << str << std::endl;
        }
        if(g_ind == 4){
            boards.emplace_back(board);
            g_ind = 0;
        }
        ind = 0;
    }

    return 0;
}