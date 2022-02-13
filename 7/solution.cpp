#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

int calcDistance(int from, int to){
    int res = 0;
    int steps = std::abs(from-to);
    for(auto step = 0; step <= steps; step++){
        res+=step;
    }
    return res;
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

int calcMean(std::vector<int> input){
    int64_t sum = 0;
    for (int pos : input) {
        sum += pos;
    }
    return static_cast<int>(std::round(static_cast<double>(sum) / static_cast<double>(input.size())));
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



    // for(auto pos: positions){
    //     std::cout << pos << " ";
    // }
    // std::cout << std::endl;
    int median = calcMedian(positions);
    int mean = calcMean(positions);
    int mean_fuel, mean_sub1_fuel, mean_sub2_fuel, mean_add1_fuel = 0;
    for(auto pos: positions){
        mean_fuel+=calcDistance(pos,mean);
        mean_sub1_fuel+=calcDistance(pos, mean-1);
        mean_add1_fuel+=calcDistance(pos, mean+1);
    }

    
    std::cout << "mean: " << mean_fuel << std::endl;
    std::cout << "sub1: " << mean_sub1_fuel << std::endl;
    std::cout << "add1: " << mean_add1_fuel << std::endl;
}