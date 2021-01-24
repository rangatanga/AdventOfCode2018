#include "aoc.h"
#include <iostream>
#include <map>
#include <string.h>
#include <boost/algorithm/string.hpp>
#include <tuple>
#include <set>
#include <chrono>

using namespace std;

int part_one(int part)
{
    auto data = read_file<std::string>("../resources/day3.txt");
    map<tuple<int, int>, int> mp;
    set<tuple<string, int, int, int, int>> ids;

    for (auto &it : data)
    {
        vector<string> offset;
        vector<string> size;
        boost::split(offset, it.substr(it.find('@') + 2, it.find(':') - it.find('@') - 2), boost::is_any_of(","));
        boost::split(size, it.substr(it.find(':') + 2, it.length() - it.find(':') - 2), boost::is_any_of("x"));
        auto id = it.substr(0, it.find(" @"));
        int x = stoi(offset[0]);
        int y = stoi(offset[1]);
        int w = stoi(size[0]);
        int h = stoi(size[1]);
        ids.insert(make_tuple(id, x, y, w, h));
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                mp[make_tuple(x + i, y + j)] += 1;
            }
        }
    }
    //part-one
    if (part == 1)
    {
        int cnt = 0;
        for (auto &it : mp)
        {
            if (it.second >= 2)
            {
                cnt++;
            }
        }
        cout << cnt;
    }
    else //part-two
    {
        for (auto &it : ids)
        {
            bool found = true;
            for (int i = 0; i < get<3>(it); i++)
            {
                for (int j = 0; j < get<4>(it); j++)
                {
                    if (mp[make_tuple(get<1>(it) + i, get<2>(it) + j)] != 1)
                    {
                        found = false;
                        break;
                    }
                }
                if (!found)
                    break;
            }
            if (found)
            {
                cout << get<0>(it) << "\n";
            }
        }
    }

    //part-two

    return 0;
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    //part_one(1);
    part_one(2);
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return 0;
}
