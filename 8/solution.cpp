// 1 - cf
// 4 - bcdf
// 7 - acf
// 8 - abcdefg
/*
  0:      1:      2:      3:      4:
 aaaa    ....    aaaa    aaaa    ....
b    c  .    c  .    c  .    c  b    c
b    c  .    c  .    c  .    c  b    c
 ....    ....    dddd    dddd    dddd
e    f  .    f  e    .  .    f  .    f
e    f  .    f  e    .  .    f  .    f
 gggg    ....    gggg    gggg    ....

  5:      6:      7:      8:      9:
 aaaa    aaaa    aaaa    aaaa    aaaa
b    .  b    .  .    c  b    c  b    c
b    .  b    .  .    c  b    c  b    c
 dddd    dddd    ....    dddd    dddd
.    f  e    f  .    f  e    f  .    f
.    f  e    f  .    f  e    f  .    f
 gggg    gggg    ....    gggg    gggg
*/

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

void setMapping(std::unordered_map<char, char>& mapping, std::string s_num){
    int size = s_num.size();
    if(size == 4){
        mapping['b'] = s_num[0];
        mapping['c'] = s_num[1];
        mapping['d'] = s_num[2];
        mapping['f'] = s_num[3];
    }
    if(size == 3){
        mapping['a'] = s_num[0];
    }
    if(size == 8){
        mapping['e'] = s_num[4];
    }
    
}
// 1 - cf
// 4 - bcdf
// 7 - acf
// 8 - abcdefg

int main()
{
    std::fstream file;
    std::string line;
    file.open("input.txt", std::ios::in);
    std::unordered_map<char, std::vector<char>> mapping;
    int count = 0;

    while (std::getline(file, line))
    {
        std::string input = line.substr(0, line.find("|") -1);
        std::cout << input << std::endl;
        std::string s_num;
        for (const char &c : input)
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
                    setMapping(mapping,s_num);
                }
                s_num = "";
            }
        }
        setMapping(mapping,s_num);
    }
    for(auto p: mapping){
        std::cout << p.first << ": ";
        for(auto c: p.second){
            std::cout << c << ",";
        }
        std::cout << std::endl;
    }
}