#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
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
    std::unordered_set<pair, pair_hash> aboveTwo;

    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    std::string line;
    int x1, y1, x2, y2;
    while (std::getline(newfile, line))
    {
        std::cout << line << std::endl;
        if (line != "")
        {
            x1 = std::stoi(line.substr(0,line.find(',')));
            y1 = std::stoi(line.substr(line.find(',')+1, line.find(' ')-std::to_string(x1).length()));
            std::string second = line.substr(line.find(' ')+3);
            x2 = std::stoi(second.substr(0, second.find(',')));
            y2 = std::stoi(second.substr(second.find(',')+1));
            
            if (x1 == x2)
            {
                for (int i = std::min(y1, y2); i <= std::max(y1, y2); i++)
                {
                    auto p = std::make_pair(i, x1);
                    vents[p]++;
                    if(vents[p] > 1){
                        aboveTwo.insert(p);
                    }
                }
            }
            if (y1 == y2)
            {
                for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++)
                {
                    auto p = std::make_pair(y1, i);
                    vents[p]++;
                    if(vents[p] > 1){
                        aboveTwo.insert(p);
                    }
                }
            }
        }
    }
    std::cout << aboveTwo.size() << std::endl;
}