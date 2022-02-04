#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>
 
typedef std::pair<int, int> pair;
 
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
int main(){
    std::unordered_map<pair, int, pair_hash> vents;
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);
    std::string line;
    int x1,y1,x2,y2;
    while (std::getline(newfile, line)){
        std::cout << line << std::endl;
        if(line != ""){
            x1 = line.at(0) - '0';
            y1 = line.at(1) - '0';;
            x2 = line.at(line.length()-3) - '0';;
            y2 = line.at(line.length()-1) - '0';;
            if(x1==x2 || y1==y2){

            }
        }
    }
}