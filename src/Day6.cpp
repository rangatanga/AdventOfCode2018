#include "aoc.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>

void part_one()
{
    ifstream in("../resources/day6.txt");
    set<tuple<int, int, int>> locs;
    set<tuple<int, int, int>> chart;
    int label = 1;
    int min_x = 9999999;
    int min_y = 9999999;
    int max_x = 0;
    int max_y = 0;

    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
        {
            int x = std::stoi(str.substr(0, str.find(", ")));
            int y = std::stoi(str.substr(str.find(", ") + 2, str.size() - (str.find(", ") + 2)));
            locs.insert(make_tuple(x, y, label));
            label++;
            min_x = std::min(min_x, x);
            min_y = std::min(min_y, y);
            max_x = std::max(max_x, x);
            max_y = std::max(max_y, y);
        }
    }
    in.close();
    for (int ix = min_x; ix <= max_x; ix++)
    {
        for (int iy = min_y; iy <= max_y; iy++)
        {
            tuple<int, int> t = make_tuple(999999, 0);
            for (auto i : locs)
            {
                auto x = std::get<0>(i);
                auto y = std::get<1>(i);
                auto l = std::get<2>(i);
                int dist = manh_distance(x, y, ix, iy);
                if (dist < get<0>(t))
                {
                    t = make_tuple(dist, l);
                }
                else if (dist == get<0>(t))
                {
                    t = make_tuple(dist, 0);
                }
            }
            chart.insert(make_tuple(ix, iy, get<1>(t)));
        }
    }
    tuple<int, int> result = make_tuple(0, 0);
    for (auto i : locs)
    {
        auto x = std::get<0>(i);
        auto y = std::get<1>(i);
        auto l = std::get<2>(i);
        int cnt = 0;
        if (x > min_x && x < max_x && y > min_y && y < max_y)
        {
            for (auto j : chart)
            {
                if (get<2>(j) == l)
                    cnt++;
            }
            if (cnt > get<0>(result))
                result = make_tuple(cnt, l);
        }
    }
    std::cout << "size: " << get<0>(result) << ", label: " << get<1>(result) << std::endl;
}

void part_two()
{
    ifstream in("../resources/day6.txt");
    set<tuple<int, int>> locs;
    int min_x = 9999999;
    int min_y = 9999999;
    int max_x = 0;
    int max_y = 0;

    string str;
    while (getline(in, str))
    {
        if (str.size() > 0)
        {
            int x = std::stoi(str.substr(0, str.find(", ")));
            int y = std::stoi(str.substr(str.find(", ") + 2, str.size() - (str.find(", ") + 2)));
            locs.insert(make_tuple(x, y));
            min_x = std::min(min_x, x);
            min_y = std::min(min_y, y);
            max_x = std::max(max_x, x);
            max_y = std::max(max_y, y);
        }
    }
    in.close();

    int region_cnt = 0;
    for (int ix = min_x; ix <= max_x; ix++)
    {
        for (int iy = min_y; iy <= max_y; iy++)
        {
            int tot_dist = 0;
            for (auto i : locs)
            {
                auto x = std::get<0>(i);
                auto y = std::get<1>(i);
                tot_dist += manh_distance(x, y, ix, iy);
            }
            if (tot_dist < 10000)
                region_cnt++;
        }
    }
    std::cout << "Region size: " << region_cnt << std::endl;
}

int main()
{
    //part_one();
    part_two();
}