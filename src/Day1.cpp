// basic file operations
#include <numeric>
#include <ranges>
#include "aoc.h"
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int part_one()
{
  auto data = read_file_ints("../resources/day1.txt");
  cout << std::accumulate(data.begin(), data.end(), 0);
  return 0;
}

int part_two()
{
  auto data = read_file_ints("../resources/day1.txt");
  set<int> freqs;
  int curFreq = 0;
  auto it = data.begin();

  while (freqs.insert(curFreq).second)
  {
    curFreq += *it;
    it++;

    if (it == data.end())
    {
      it = data.begin();
    }
  };

  cout << curFreq;
  return 0;
}

int main()
{
  part_two();
  return 0;
}
