//#include "aoc.h"
#include <iostream>
//#include <algorithm>
//#include <set>
//#include <string>
#include <list>
#include <map>

void part_one(int playerCnt, int lastMarble)
{
    int currPlayer = 1;
    std::list<int> circle;
    std::list<int>::iterator currMarble;
    std::map<int, unsigned long int> scores;

    //init
    circle.push_back(0);
    currMarble = circle.begin();

    //play
    for (int m = 1; m <= lastMarble; ++m)
    {
        if (currPlayer > playerCnt)
        {
            currPlayer = 1;
        }

        if (m % 23 == 0)
        {
            scores[currPlayer] += m;
            for (int i = 0; i < 7; ++i)
            {
                if (currMarble == circle.begin())
                {
                    currMarble = circle.end();
                }
                --currMarble;
            }

            //std::cout << m << " + " << *currMarble << std::endl;

            scores[currPlayer] += *currMarble;
            currMarble = circle.erase(currMarble);
            if (currMarble == circle.end())
            {
                currMarble = circle.begin();
            }
        }
        else
        {
            if (circle.size() == 1)
            {
                circle.push_back(m);
                ++currMarble;
            }
            else
            {
                for (int i = 0; i < 2; ++i)
                {
                    ++currMarble;
                    if (currMarble == circle.end())
                    {
                        currMarble = circle.begin();
                    }
                }
                circle.insert(currMarble, m);
                --currMarble;
            }
        }
        currPlayer++;
        /*
        for (auto tit = circle.begin(); tit != circle.end(); ++tit)
        {
            std::cout << ' ' << *tit;
        }
        std::cout << '\n';
        */
    }

    unsigned long int maxScore = 0;
    for (auto &s : scores)
    {
        maxScore = std::max(maxScore, s.second);
    }
    std::cout << lastMarble << " : " << maxScore << std::endl;
}

void part_two()
{
    //std::cout << eval_meta(data, 0).second << std::endl;
}

int main()
{
    //part_one(405, 70953);
    //part two (changed to use unsigned long int to store score)
    part_one(405, 7095300);
}