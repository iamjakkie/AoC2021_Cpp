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

void setMapping(std::string s_num){
    
}

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
                    int size = s_num.size();
                    if (size == 2)
                    {
                        mapping['c'] = s_num[0];
                        mapping['f'] = s_num[1];
                    }
                }
                s_num = "";
            }
        }
        int size = s_num.size();
        if (size == 2 || size == 3 || size == 4 || size == 7)
        {
            count++;
        }
    }
    std::cout << count << std::endl;
}