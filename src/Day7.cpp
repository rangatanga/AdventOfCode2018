#include "aoc.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <queue>

void part_one()
{
    ifstream in("../resources/day7.txt");
    map<string, set<string>> rules;
    set<string> steps;
    set<string> prereqs;

    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
        {
            rules[str.substr(36, 1)].insert(str.substr(5, 1));
            prereqs.insert(str.substr(5, 1));
            steps.insert(str.substr(36, 1));
        }
    }
    in.close();

    string step_order = "";
    for (auto s : prereqs)
    {
        if (steps.count(s) == 0)
        {
            step_order += s;
            for (auto it = rules.begin(); it != rules.end(); ++it)
            {
                it->second.erase(s);
            }
        }
    }

    std::sort(step_order.begin(), step_order.end());

    while (true)
    {
        string so = "";
        for (auto it = rules.begin(); it != rules.end(); ++it)
        {
            if (it->second.size() == 0 && step_order.find(it->first) == string::npos)
            {
                so += it->first;
            }
        }
        if (so == "")
            break;

        std::sort(so.begin(), so.end());
        step_order += so[0];

        for (auto it = rules.begin(); it != rules.end(); ++it)
        {
            it->second.erase(so.substr(0, 1));
        }
    }
    std::cout << step_order << std::endl;
}

struct Worker
{
    string step;
    int time_remain;
};

void part_two()
{
    string q;

    ifstream in("../resources/day7.txt");
    map<string, set<string>> rules;
    set<string> steps;
    set<string> prereqs;

    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
        {
            rules[str.substr(36, 1)].insert(str.substr(5, 1));
            prereqs.insert(str.substr(5, 1));
            steps.insert(str.substr(36, 1));
        }
    }
    in.close();

    for (auto s : prereqs)
    {
        if (steps.count(s) == 0)
        {
            q += s;
        }
    }
    std::sort(q.begin(), q.end());

    Worker ws[5];
    int sec = 0;
    string step_order = "";
    string steps_run = "";

    bool loop = true;
    while (loop)
    {
        loop = false;
        for (int i = 0; i < 5; ++i)
        {
            if (ws[i].step == "")
            {
                if (q.size() > 0)
                {
                    ws[i].step = q[0];
                    q = q.substr(1, q.size() - 1);
                    ws[i].time_remain = 60 + (int)ws[i].step[0] - 64;
                    steps_run += ws[i].step;
                    loop = true;
                }
            }
            else
            {
                ws[i].time_remain -= 1;
                if (ws[i].time_remain == 0)
                {
                    step_order += ws[i].step;
                    for (auto it = rules.begin(); it != rules.end(); ++it)
                    {
                        it->second.erase(ws[i].step);
                        if (it->second.size() == 0 && step_order.find(it->first) == string::npos && steps_run.find(it->first) == string::npos && q.find(it->first) == string::npos)
                        {
                            q += it->first;
                        }
                    }
                    std::sort(q.begin(), q.end());
                    ws[i].step = "";
                    if (q.size() > 0)
                    {
                        ws[i].step = q[0];
                        q = q.substr(1, q.size() - 1);
                        ws[i].time_remain = 60 + (int)ws[i].step[0] - 64;
                        steps_run += ws[i].step;
                        loop = true;
                    }
                }
                else
                {
                    loop = true;
                }
            }
        }
        std::cout << sec << ", " << ws[0].step << ws[0].time_remain << ", " << ws[1].step << ", " << ws[2].step << ", " << ws[3].step << ", " << ws[4].step << ", " << step_order << std::endl;
        sec++;
    }
}

int main()
{
    //part_one();
    part_two();
}