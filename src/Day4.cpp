#include "aoc.h"
#include <iostream>
#include <map>
#include <string.h>
#include <boost/algorithm/string.hpp>
#include <tuple>
#include <set>
#include <chrono>
//#include <boost/date_time.hpp>

using namespace std;
//using namespace boost::posix_time;

int part_one()
{
    auto data = read_file<std::string>("../resources/day4.txt");
    map<ptime, string> mp;

    for (auto &it : data)
    {
        auto dt = boost::posix_time::time_from_string(it.substr(1, 16));
        string action = it.substr(19, it.length() - 19);
        mp[dt] = action;
    }

    int guard_id;
    ptime start;
    map<int, map<int, int>> guard_minute_map;
    map<int, int> guard_map;
    for (auto &it : mp)
    {
        if (it.second.substr(0, 5) == "Guard")
        {
            guard_id = stoi(it.second.substr(7, it.second.find(" begins") - 7));
        }
        else if (it.second == "falls asleep")
        {
            start = it.first;
        }
        else if (it.second == "wakes up")
        {
            boost::posix_time::time_duration td = it.first - start;
            guard_map[guard_id] += td.minutes() - 1;
            for (int i = 0; i < td.minutes(); i++)
            {
                guard_minute_map[guard_id][(start + boost::posix_time::minutes(i)).time_of_day().minutes()] += 1;
            }
        }
        //cout << it.first << ", " << it.second << ", " << guard_id << "\n";
    }
    //part-one
    int max_min = 0;
    for (auto &it : guard_map)
    {
        if (it.second > max_min)
        {
            max_min = it.second;
            guard_id = it.first;
        }
    }

    max_min = 0;
    int sleep_min;
    for (auto &it : guard_minute_map[guard_id])
    {
        if (it.second > max_min)
        {
            max_min = it.second;
            sleep_min = it.first;
        }
    }
    cout << guard_id * sleep_min << "\n";

    //part-two
    max_min = 0;
    for (auto &it : guard_minute_map)
    {
        for (auto &it2 : it.second)
        {
            if (it2.second > max_min)
            {
                max_min = it2.second;
                guard_id = it.first;
                sleep_min = it2.first;
            }
        }
    }
    cout << guard_id * sleep_min << "\n";

    return 0;
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    part_one();
    auto t2 = std::chrono::high_resolution_clock::now();
    cout << "\n"
         << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return 0;
}
