#include <fstream>
#include <string>
#include <vector>
#include <iostream>

int calcSingle(int day, int length){
    return (length-day-1)/7+1;
}

int calcFunc(std::vector<int> init, int day){
    int sum = init.size();
    for(auto fish:init){
        int start = fish;
        int days = day;
        int calc = calcSingle(start, days);
        sum+=calc;
        while(calc > 1){
            days = days - day;
            calc = calcSingle(6, )
        }
        sum += 1 + calcSingle(fish, day);
        std::cout << fish << ": " << calcSingle(fish, day) << std::endl;
    }
    return sum;
}

int main(){
    std::fstream newfile;
    std::string line;
    newfile.open("input.txt", std::ios::in);
    std::getline(newfile, line);
    std::string s_num = "";
    std::vector<int> fish;
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
                        fish.emplace_back(std::stoi(s_num));
                    }
                    s_num = "";
                }
            }
    fish.emplace_back(std::stoi(s_num));
    // for(int i = 0; i < 256; i++){
    //     int size = fish.size();
    //     for(int fn = size-1; fn >= 0; fn--){
    //         if(fish[fn] == 0){
    //             fish[fn] = 6;
    //             fish.emplace_back(8);
    //             continue;
    //         }
    //         fish[fn]--;
    //     }
    //     // std::cout << "After day " << std::to_string(i+1) << " ";
    //     // for(auto f:fish){
    //     //     std::cout << f << ",";
    //     // }
    //     // std::cout << std::endl;
    // }

    std::cout << calcFunc(fish, 18) << std::endl;

    
}