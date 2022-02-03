#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>

#include "board.h"

constexpr int size = 5;

int main()
{
    std::string str = "";
    std::string guesses = "";
    std::vector<Board> boards;
    int g_ind = 0;
    int ind = 0;
    int read = 0;
    std::array<std::array<int, size>, size> board;
    std::fstream newfile;
    newfile.open("input.txt", std::ios::in);

    while (std::getline(newfile, str))
    {
        if (read == 0)
        {
            guesses = str;
            read++;
            continue;
        }
        if (read < 2)
        {
            read++;
            continue;
        }
        std::array<int, size> arr;
        if (str != "")
        {
            std::string s_num = "";
            bool space = false;
            for (char const &c : str)
            {
                if (c != ' ')
                {
                    s_num += c;
                    continue;
                }
                else
                {
                    if (s_num != "")
                    {
                        arr[ind++] = std::stoi(s_num);
                    }
                    s_num = "";
                }
            }
            arr[ind++] = std::stoi(s_num);
            board[g_ind++] = arr;
            ind = 0;
        }
        // ind = 0;
        // std::cout << std::to_string(board.size());
        if (g_ind == size)
        {
            boards.emplace_back(Board(board));
            g_ind = 0;
        }
    }
    newfile.close();

    std::cout << guesses << std::endl;
    for (auto board : boards)
    {
        std::cout << board;
    }

    std::string guess;
    Board *found = nullptr;
    for (const char &c : guesses)
    {
        if (found == nullptr)
        {
            if (c != ',')
            {
                guess += c;
                continue;
            }
            else
            {
                if (guess != "")
                {
                    std::cout << guess << std::endl;
                    for (Board &b : boards)
                    {
                        bool check = b.checkNumber(std::stoi(guess));
                        if (check)
                        {
                            std::cout << "Last num:" << guess << std::endl;
                            found = &b;
                        }
                    }
                }
                guess = "";
            }
        } else{
            break;
        }
    }
    std::cout << guess << std::endl;

    std::cout << *found;

    return 0;
}