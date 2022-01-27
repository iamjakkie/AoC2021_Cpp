#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

enum class Order
{
    forward,
    up,
    down
};

bool isNumber(const std::string &s)
{
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

int main()
{
    std::ifstream file("input.txt");
    std::string str, order;
    int val, position, depth = 0;
    while (std::getline(file, str))
    {
        std::stringstream linestream(str);
        std::getline(linestream, order, ' ');
        linestream >> val;
        if(order == "forward"){
            position+=val;
        } else if (order == "up")
        {
            depth-=val;
        } else if (order == "down"){
            depth+=val;
        }
    }
    std::cout << "Position: " << std::to_string(position) << " depth: " << std::to_string(depth) << std::endl;
    int final = position*depth;
    std::cout << std::to_string(final) << std::endl;

    return 0;
}