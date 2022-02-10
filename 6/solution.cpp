#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "lanternfish.h"

int main(){
    std::fstream newfile;
    std::string line;
    newfile.open("input.txt", std::ios::in);
    std::getline(newfile, line);
    std::string s_num = "";
    std::vector<Lanternfish> fish;
    std::cout << line << std::endl;
    for (char const &c : line)
    
            {
                if (c != ',')
                {
                    s_num += c;
                    continue;
                }
                else
                {
                    if (s_num != "")
                    {
                        fish.emplace_back(Lanternfish(std::stoi(s_num)));
                    }
                    s_num = "";
                }
            }
    fish.emplace_back(Lanternfish(std::stoi(s_num)));
    std::cout << "Initial State: ";
    for(auto f:fish){
        std::cout << f.getDay() << ",";
    }
    std::cout << std::endl;
    for(int i = 0; i < 19; i++){
        int c = 0;
        for(int fn = 0; fn < fish.size(); fn++){
            auto new_f = fish[fn].moveTimer();
            if(new_f){
                c++;
            }
        }
        for(int j = 0; j < c; j++){
            fish.emplace_back(Lanternfish{});
        }
        std::cout << "After day " << std::to_string(i+1) << " ";
        for(auto f:fish){
            std::cout << f.getDay() << ",";
        }
        std::cout << std::endl;
    }

    
}