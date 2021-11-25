#include "aoc.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

vector<tuple<int, int, int, int>> get_data()
{
    ifstream in("../resources/day10.txt");
    vector<tuple<int, int, int, int>> stars;
    string str;

    while (getline(in, str))
    {
        if (str.size() > 0)
        {
            int pos_x = std::stoi(str.substr(10, str.find(", ") - 10));
            int pos_y = std::stoi(str.substr(str.find(",") + 2, str.find("> ") - str.find(",") + 2));
            auto v = str.substr(str.find("y=<") + 3);
            int vel_x = std::stoi(v.substr(0, str.find(",")));
            int vel_y = std::stoi(v.substr(v.find(",") + 2, str.find("> ") - str.find(",") + 2));
            stars.push_back(make_tuple(pos_x, pos_y, vel_x, vel_y));
        }
    }
    in.close();
    return stars;
}

tuple<int, int, int, int> update_location(tuple<int, int, int, int> star)
{
    return make_tuple(get<0>(star) + get<2>(star), get<1>(star) + get<3>(star), get<2>(star), get<3>(star));
}

void display_stars(map<int, vector<int>> &star_map, int &min_x, int &max_x)
{
    cout << std::endl;
    for (auto iter = star_map.begin(); iter != star_map.end(); ++iter)
    {
        std::string s(max_x - min_x, ' ');
        for (int i = 0; i < iter->second.size(); ++i)
        {
            s.replace(iter->second[i] - min_x, 1, "#");
        }
        std::cout << s << std::endl;
    }
}

void part_one()
{
    auto data = get_data();
    bool cont = true, build_map = false;
    ;
    int max_x = 0, min_x = 9999999, max_y = 0, min_y = 9999999, seconds = 0;

    while (cont)
    {
        seconds++;
        map<int, vector<int>> mp;

        int max_x = 0, min_x = 9999999, max_y = 0, min_y = 9999999;
        for (int i = 0; i < data.size(); ++i)
        {
            auto new_star = update_location(data.at(i));
            data.at(i) = new_star;

            if (build_map)
                mp[get<1>(new_star)].push_back(get<0>(new_star));

            min_x = min(min_x, get<0>(new_star));
            max_x = max(max_x, get<0>(new_star));
            min_y = min(min_y, get<1>(new_star));
            max_y = max(max_y, get<1>(new_star));
        }

        //std::cout << min_y << ", " << max_y << std::endl;

        if (max_y - min_y <= 12)
        {
            build_map = true;
            display_stars(mp, min_x, max_x);
            std::cout << "seconds: " << seconds << std::endl;
        }
        else
        {
            if (build_map)
                cont = false;
        }
    }
}

int main()
{
    part_one();
}