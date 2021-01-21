#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

std::vector<int> read_file_ints(std::string filename)
{
    std::ifstream in(filename);
    std::vector<int> result;
    std::copy(std::istream_iterator<int>(in),
              std::istream_iterator<int>(),
              std::back_inserter(result));
    return result;
}
