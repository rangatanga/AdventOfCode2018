#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>

template <typename T>
std::vector<T> read_file(std::string filename)
{
    std::ifstream in(filename);
    std::vector<T> result;
    std::copy(std::istream_iterator<T>(in),
              std::istream_iterator<T>(),
              std::back_inserter(result));
    return result;
}

template <typename T1, typename T2>
bool find_map_value(std::map<T1, T2> m, T2 x)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it->second == x)
            return true;
    }
    return false;
}

std::tuple<int, int> count_repeat_chars(std::string str)
{
    std::map<char, int> m;
    for (char const &c : str)
    {
        auto x = m[c];
        m[c]++;
    };

    return std::make_tuple<int, int>((find_map_value<char, int>(m, 2)) ? 1 : 0, (find_map_value<char, int>(m, 3)) ? 1 : 0);
}

int string_diff(std::string str1, std::string str2)
{
    int result;
    for (int i = 0; i < str1.length(); i++)
    {
        result += (str1[i] != str2[i] ? 1 : 0);
    }
    return result;
}

std::string string_common(std::string str1, std::string str2)
{
    std::string result = "";
    for (int i = 0; i < str1.length(); i++)
    {
        result += (str1[i] == str2[i] ? str1[i] : '\0');
    }
    return result;
}
