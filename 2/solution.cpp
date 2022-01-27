#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

int main()
{
    std::ifstream file("input.txt");
    std::string str, order, skip;
    int val, position, depth, aim = 0;
    while (file >> order >> val)
    {
        if(order == "forward"){
            position+=val;
            int inc = aim*val;
            depth+=inc;
        } else if (order == "up")
        {
            aim-=val;
        } else if (order == "down"){
            aim+=val;
        }
    }
    std::cout << "Position: " << std::to_string(position) << " depth: " << std::to_string(depth) << std::endl;
    int final = position*depth;
    std::cout << std::to_string(final) << std::endl;

    return 0;
}