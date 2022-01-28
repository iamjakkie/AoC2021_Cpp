#include <fstream>
#include <iostream>
#include <bitset>
#define SIZE 12

int main()
{
    std::ifstream file("input.txt");
    int oneCounts[SIZE];
    int cnt = 0;
    std::string val;
    std::bitset<SIZE> gamma, epsilon;
    while (file >> val)
    {
        std::bitset<SIZE> bs(val);
        for (auto i = 0; i < SIZE; i++)
        {
            if (bs[i] == 1)
            {
                oneCounts[i]++;
            }
        }
        cnt++;
    }

    for(auto i=0; i<SIZE; i++){
        int ones = oneCounts[i];
        int zeros = cnt-oneCounts[i];
        gamma[i] = (ones>zeros) ? 1 : 0;
    }
    epsilon = gamma;
    epsilon = epsilon.flip();
    int iGamma = gamma.to_ulong();
    int iEpsilon = epsilon.to_ulong();
    int res = iGamma*iEpsilon;
    std::cout << std::to_string(res) << std::endl;
    return 0;
}