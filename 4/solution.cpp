#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <unordered_set>

#include "board.h"

constexpr int size = 5;

int main()
{
    int boardNum = 1;
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
            boards.emplace_back(Board(board, boardNum++));
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
    std::unordered_set<int> solvedBoards;
    for (const char &c : guesses)
    {
        if (solvedBoards.size() != 100)
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
                    for (Board &b : boards)
                    {
                        bool check = b.checkNumber(std::stoi(guess));
                        if (check)
                        {
                            if (solvedBoards.insert(b.getId()).second)
                            {

                                if (solvedBoards.size() == 100)
                                {
                                    std::cout << "====100====" << std::endl;
                                    std::cout << "Last num:" << guess << std::endl;
                                    std::cout << b.getUnmarked() << std::endl;
                                }
                            }
                        }
                    }
                }
                guess = "";
            }
        }
        else
        {
            break;
        }
    }
    if (solvedBoards.size() != 100)
    {
        for (Board &b : boards)
        {
            bool check = b.checkNumber(std::stoi(guess));
            if (check)
            {

                if (solvedBoards.insert(b.getId()).second)
                {
                    std::cout << solvedBoards.size() << " curr:" << b.getId() << std::endl;
                    if (solvedBoards.size() == 100)
                    {
                        std::cout << "Last num:" << guess << std::endl;
                        std::cout << b.getUnmarked() << std::endl;
                    }
                }
            }
        }
    }
    std::cout << guesses << std::endl;

    return 0;
}