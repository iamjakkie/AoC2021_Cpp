#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int calcDistance(int from, int to){
    return std::abs(from-to);
}

int calcMedian(std::vector<int> input){
    if (input.size() % 2 == 0) {
    const auto median_it1 = input.begin() + input.size() / 2 - 1;
    const auto median_it2 = input.begin() + input.size() / 2;

    std::nth_element(input.begin(), median_it1 , input.end());
    const auto e1 = *median_it1;

    std::nth_element(input.begin(), median_it2 , input.end());
    const auto e2 = *median_it2;

    return (e1 + e2) / 2;

    } else {
        const auto median_it = input.begin() + input.size() / 2;
        std::nth_element(input.begin(), median_it , input.end());
        return *median_it;
    }
}

int main() {
    std::fstream file;
    std::string line;
    file.open("input.txt", std::ios::in);
    std::getline(file, line);
    std::string s_num = "";
    std::vector<int> positions;
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
                        positions.emplace_back(std::stoi(s_num));
                    }
                    s_num = "";
                }
            }
    positions.emplace_back(std::stoi(s_num));



    for(auto pos: positions){
        std::cout << pos << " ";
    }
    std::cout << std::endl;
    std::cout << 
}