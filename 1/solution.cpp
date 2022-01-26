#include <fstream>
#include <string>
#include <iostream>
#include <queue>

int increasedSlidingWindows(int size = 1)
{
    std::ifstream file("input.txt");
    std::string str;
    int curr, prev;
    int cnt = 0;
    if (size == 1)
    {
        while (std::getline(file, str))
        {
            curr = std::stoi(str);
            if (prev)
            {
                if (curr > prev)
                {
                    cnt++;
                }
            }
            prev = curr;
        }
        return cnt;
    } else{
        std::queue<int> window;
        for(auto i = 0; i < size; i++){
            std::getline(file, str);
            auto temp = std::stoi(str);
            window.push(temp);
            curr+=temp;
        }
        prev = curr;
        while (std::getline(file, str))
        {   
            // prev = curr;
            curr -= window.front();
            window.pop();
            auto temp = std::stoi(str);
            curr += temp; 
            window.push(temp);
            // std::cout << "Prev: " << std::to_string(prev) << " Curr: " << std::to_string(curr) << std::endl;
            if (curr > prev)
            {
                cnt++;
            }
            prev = curr;
        }
        return cnt;
    }
}

int main()
{

    std::cout << std::to_string(increasedSlidingWindows(3)) << std::endl;
    return 0;
}