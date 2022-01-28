#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#define SIZE 12

bool getMostCommonBit(const std::vector<std::bitset<SIZE>>& nums, int pos){
    int ones = 0;
    for(auto i: nums){
        ones += (i[pos]==1) ? 1:0;
    }
    return ones >= (nums.size()-ones);
}

bool getLeastCommonBit(const std::vector<std::bitset<SIZE>>& nums, int pos){
    int ones = 0;
    for(auto i: nums){
        ones+=(i[pos]==1) ? 1 : 0;
    }
    return ones < (nums.size()-ones);
}

int main()
{
    std::ifstream file("input.txt");
    int firstOneCount;
    std::string val;
    std::vector<std::bitset<SIZE>> oxygenBitset, oxygenFiltered, co2Bitset, co2Filtered;
    std::bitset<SIZE> oxygen, co2;
    while (file >> val)
    {
        std::bitset<SIZE> bs(val);
        if(bs[SIZE-1]==1){
            firstOneCount++;
        }
        oxygenBitset.emplace_back(bs);
        co2Bitset.emplace_back(bs);
    }
    bool mostCommon = getMostCommonBit(oxygenBitset, SIZE-1);
    bool leastCommon = !mostCommon;
    for(int i; i<oxygenBitset.size(); i++){
        if(oxygenBitset[i][SIZE-1] == mostCommon){
            oxygenFiltered.emplace_back(oxygenBitset[i]);
        }
        if(co2Bitset[i][SIZE-1] == leastCommon){
            co2Filtered.emplace_back(co2Bitset[i]);
        }
    }

    for(int i = SIZE-2; i>=0; i--){
        oxygenBitset = oxygenFiltered;
        co2Bitset = co2Filtered;
        oxygenFiltered.clear();
        co2Filtered.clear();
        mostCommon = getMostCommonBit(oxygenBitset, i);
        leastCommon = getLeastCommonBit(co2Bitset, i);
        for(auto bs:oxygenBitset){
            if(bs[i] == mostCommon){
                oxygenFiltered.emplace_back(bs);
            }
        }
        for(auto bs:co2Bitset){
            if(bs[i] == leastCommon){
                co2Filtered.emplace_back(bs);
            }
        }
        if(oxygenFiltered.size() == 1){
            oxygen = oxygenFiltered.front();
        }
        if(co2Filtered.size() == 1){
            co2 = co2Filtered.front();
        }
    }
    std::cout << oxygen.to_ulong() << std::endl;
    std::cout << co2.to_ulong() << std::endl;

    
    
    return 0;
}