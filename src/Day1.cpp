// basic file operations
#include <numeric>
#include <ranges>
#include "aoc.h"
#include <vector>
#include <iostream>
#include <set>
//using namespace std;

int part_one()
{
  auto data = read_file<int>("../resources/day1.txt");
  std::cout << std::accumulate(data.begin(), data.end(), 0);
  return 0;
}

int part_two()
{
  auto data = read_file<int>("../resources/day1.txt");
  std::set<int> freqs;
  int curFreq = 0;
  auto it = data.begin();

  while (freqs.insert(curFreq).second) //insert returns a fail if element already exists
  {
    curFreq += *it;
    it++;

    if (it == data.end())
    {
      it = data.begin();
    }
  };

  std::cout << curFreq;
  return 0;
}

int main()
{
  part_two();
  return 0;
}
