// basic file operations
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


std::vector<int> read_ints(std::istream& is)
{
    std::vector<int> result;
    std::copy(std::istream_iterator<int>(is),
              std::istream_iterator<int>(),
              std::back_inserter(result));
    return result;
}

int main()
{
  ifstream myfile;
  string line;
  myfile.open("D:/Development/AdventOfCode2018/resources/day1.txt");

  if (myfile.is_open())
  {
    auto data = read_ints (myfile);
  }
  else
  {
    cout << "File not found";
  }

  myfile.close();
  return 0;
}