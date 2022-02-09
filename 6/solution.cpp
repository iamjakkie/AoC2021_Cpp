#include <fstream>
#include <string>
#include <vector>

#include "lanternfish.h"

int main(){
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    std::string line;
    std::getline(newfile, line);
    std::string s_num = "";
    std::vector<Lanternfish> fish;

    for (char const &c : line)
            {
                if (c != ' ')
                {
                    s_num += c;
                    continue;
                }
                else
                {
                    if (s_num != "")
                    {
                        fish.emplace_back(new Lanternfish(std::stoi(s_num)));
                    }
                    s_num = "";
                }
            }
            
}