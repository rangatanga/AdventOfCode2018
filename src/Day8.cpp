#include "aoc.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>

// 2 3 0 3 10 11 12 1 1 0 1 99 2 1 1 2

pair<int, int> sum_meta(const vector<std::string> &data, int pos, int meta_sum)
{
    auto child_cnt = stoi(data[pos]);
    auto meta_cnt = stoi(data[pos + 1]);
    pos = pos + 2;

    for (int i = 1; i <= child_cnt; ++i)
    {
        tie(pos, meta_sum) = sum_meta(data, pos, meta_sum);
    }
    for (int i = 1; i <= meta_cnt; ++i)
    {
        meta_sum += stoi(data[pos]);
        pos++;
    }

    return make_pair(pos, meta_sum);
}

pair<int, int> eval_meta(const vector<std::string> &data, int pos)
{
    auto child_cnt = stoi(data[pos]);
    auto meta_cnt = stoi(data[pos + 1]);
    int meta_sum = 0;
    pos = pos + 2;

    vector<int> children;
    children.push_back(0);

    for (int i = 1; i <= child_cnt; ++i)
    {
        int res;
        tie(pos, res) = eval_meta(data, pos);
        children.push_back(res);
    }
    if (child_cnt == 0)
    {
        for (int i = 1; i <= meta_cnt; ++i)
        {
            meta_sum += stoi(data[pos]);
            pos++;
        }
    }
    else
    {
        for (int i = 1; i <= meta_cnt; ++i)
        {
            auto index = stoi(data[pos]);
            if (index > 0 && index < children.size())
            {
                meta_sum += children[index];
            }
            pos++;
        }
    }

    return make_pair(pos, meta_sum);
}

std::vector<std::string> get_data()
{
    ifstream in("../resources/day8.txt");
    std::istream_iterator<std::string> begin(in);
    std::istream_iterator<std::string> end;
    std::vector<std::string> data(begin, end);
    return data;
}

void part_one()
{
    auto data = get_data();
    std::cout << sum_meta(data, 0, 0).second << std::endl;
}

void part_two()
{
    auto data = get_data();
    std::cout << eval_meta(data, 0).second << std::endl;
}

int main()
{
    //part_one();
    part_two();
}