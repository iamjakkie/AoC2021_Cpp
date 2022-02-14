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

int main()
{
    std::fstream file;
    std::string line;
    file.open("input.txt", std::ios::in);
    int count = 0;

    while (std::getline(file, line))
    {
        std::string nums = line.substr(line.find("|") + 2);
        std::string s_num;
        for (const char &c : nums)
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
                    if (size == 2 || size == 3 || size == 4 || size == 7)
                    {
                        count++;
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