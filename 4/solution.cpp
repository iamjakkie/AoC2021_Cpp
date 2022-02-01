#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>

#define SIZE = 5

int main(){
    std::string str = "";
    std::string guesses = "";
    std::vector<std::array<std::array<int, 5>, 5>> boards;
    int g_ind = 0;
    int ind = 0; 
    int read = 0;
    std::array<std::array<int, 5>, 5> board;
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);

    while(std::getline(newfile, str)){
        if(read==0){
            guesses = str;
            read++;
            continue;
        }
        std::array<int, 5> arr;
        if(str != ""){
            std::cout << str << std::endl;
            std::string s_num = "";
            bool space = false;
            for(char const& c: str){
                if(c != ' '){
                    s_num += c;
                    continue;
                } else{
                    if(s_num != ""){
                        arr[ind++] = std::stoi(s_num);
                    }
                    s_num = "";
                }
            }
            arr[ind++] = std::stoi(s_num);
        } else{
            std::cout << std::endl;
            board[g_ind++] = arr;
            ind = 0;
        }
        // std::cout << std::to_string(board.size());
        if(g_ind == 4){
            boards.emplace_back(board);
            g_ind = 0;
        }
        ind = 0;
    }
    newfile.close();

    for(auto board:boards){
        for(auto arr:board){
            for(auto num:arr){
                std::cout << std::to_string(num) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}