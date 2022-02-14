// 1 - cf
// 4 - bcdf
// 7 - acf
// 8 - abcdefg

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