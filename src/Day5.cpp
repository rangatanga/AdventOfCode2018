#include "aoc.h"
#include <iostream>
#include <algorithm>

int main()
{
    size_t lowest = 999999999999;
    for (char x = 'a'; x <= 'z'; x++)
    {
        ifstream in("../resources/day5.txt");

        string str;
        char c;
        // Read the next line from File untill it reaches the end.
        while (in.get(c))
        {
            if (tolower(c) != x)
            {
                char last = str.size() == 0 ? '\0' : str.back();
                if (toupper(last) == toupper(c) && last != c)
                {
                    str.pop_back();
                }
                else
                {
                    str += c;
                }
            }
        }
        in.close();

        std::cout << x << ": " << str.size() << std::endl;
        lowest = std::min(lowest, str.size());
    }
    std::cout << lowest << std::endl;
}
