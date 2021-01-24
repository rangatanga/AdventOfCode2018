#include "aoc.h"
#include <iostream>

int part_one()
{
    auto data = read_file<std::string>("../resources/day2.txt");
    int tw, th;

    for (auto &it : data)
    {
        auto x = count_repeat_chars(it);
        tw += std::get<0>(x);
        th += std::get<1>(x);
    }
    std::cout << tw * th;
    return 0;
}

int part_two()
{
    auto data = read_file<std::string>("../resources/day2.txt");
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        for (auto it2 = data.rbegin(); it2 != data.rend(); ++it2)
        {
            if (string_diff(*it, *it2) == 1)
            {
                std::cout << string_common(*it, *it2) << "\n";
                return 0;
            }
        }
    }
}

int main()
{
    //part_one();
    part_two();
    return 0;
}
