#include <fstream>
#include <string>
#include <iostream>

int main(){
    
    std::ifstream file("input.txt");
    std::string str;
    int num, prev;
    int cnt = 0;
    while (std::getline(file, str))
    {
        num = std::stoi(str);
        if(prev){
            if(num > prev){
                cnt++;
            }
        } 
        prev = num;
    }

    std::cout << std::to_string(cnt) << std::endl;
    return 0;
}