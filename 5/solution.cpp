#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>

typedef std::pair<int, int> pair;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
int main()
{
    std::unordered_map<pair, int, pair_hash> vents;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            vents[std::make_pair(i, j)] = 0;
        }
    }

    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    std::string line;
    int x1, y1, x2, y2;
    while (std::getline(newfile, line))
    {
        std::cout << line << std::endl;
        if (line != "")
        {
            for(const char& c:line){
                
            }
            x1 = line.at(0) - '0';
            y1 = line.at(2) - '0';
            ;
            x2 = line.at(line.length() - 3) - '0';
            ;
            y2 = line.at(line.length() - 1) - '0';
            ;
            if (x1 == x2)
            {
                for (int i = std::min(y1, y2); i <= std::max(y1, y2); i++)
                {
                    vents[std::make_pair(i, x1)]++;
                }
            }
            if (y1 == y2)
            {
                for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++)
                {
                    vents[std::make_pair(y1, i)]++;
                }
            }
        }
    }
    int aboveTwo = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(vents[std::make_pair(i,j)] > 1){
                aboveTwo++;
            }
        }
    }
    std::cout << aboveTwo << std::endl;
}