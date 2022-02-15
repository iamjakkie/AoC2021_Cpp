

#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

void setMapping(std::unordered_map<char, char>& mapping, std::unordered_set<char>& full, std::string s_num){
    int size = s_num.size();
    if(size == 4){
        // mapping['b'] = s_num[0];
        mapping[s_num[0]] = 'b';
        full.erase(s_num[0]);
        // mapping['c'] = s_num[1];
        mapping[s_num[1]] = 'c';
        full.erase(s_num[1]);
        // mapping['d'] = s_num[2];
        mapping[s_num[2]] = 'd';
        full.erase(s_num[2]);
        // mapping['f'] = s_num[3];
        mapping[s_num[3]] = 'f';
        full.erase(s_num[3]);
    }
    if(size == 3){
        // mapping['a'] = s_num[0];
        mapping[s_num[0]] = 'a';
        full.erase(s_num[0]);
    }
    if(size == 7){
        // mapping['e'] = s_num[4];
        mapping[s_num[4]] = 'e';
        full.erase(s_num[4]);
    } if(full.size() == 1){
        // mapping['g'] = *(full.begin());
        mapping[*(full.begin())] = 'g';
    }

}

char translate(std::unordered_map<std::string, int>& translated, std::unordered_map<char, char>& mapping, std::string s_num){
    int size = s_num.size();
    if(size == 2){
        return '1';
    } else if(size == 4){
        return '4';
    } else if(size == 3){
        return '7';
    } else if(size == 7){
        return '8';
    } else{
        std::string t_num = "";
        for(auto c: s_num){
            t_num+=mapping[c];
        }
        std::sort(t_num.begin(), t_num.end());
        // std::cout << static_cast<char>(translated[t_num]) << std::endl;
        return *std::to_string(translated[t_num]).c_str();
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
    std::unordered_map<char, char> mapping;
    std::unordered_map<std::string, int> translated {
        {"abcefg",0},
        {"acdeg",2},
        {"acdfg",3},
        {"abdfg",5},
        {"abdefg",6},
        {"abcdfg",9}};
    int total = 0;
    while (std::getline(file, line))
    {
        std::unordered_set<char> full {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        std::string input = line.substr(0, line.find("|") -1);
        std::string nums = line.substr(line.find("|")+2);
        // std::cout << input << std::endl;
        // std::cout << nums << std::endl;
        std::string numbers ="";
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
                    setMapping(mapping, full, s_num);
                }
                s_num = "";
            }
        }
        setMapping(mapping,full, s_num);

    //     for(auto c: mapping){
    //     std::cout << c.first << ": " << c.second << std::endl;
    // }
        s_num = "";
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
                    // std::cout << s_num << std::endl;
                    numbers+=translate(translated, mapping, s_num);
                }
                s_num = "";
            }
        }
        numbers+=translate(translated, mapping, s_num);

        std::cout << "Num:" << numbers << std::endl;
        total+=std::stoi(numbers);
    }

    std::cout << total << std::endl;

    
    
}