#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost::posix_time;

template <typename T>
vector<T> read_file(const string &filename)
{
    ifstream in(filename);
    vector<T> result;

    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 0)
            result.push_back(str);
    }
    in.close();
    return result;
}

template <>
vector<int> read_file(const string &filename)
{
    ifstream in(filename);
    vector<int> result;

    string str;
    while (getline(in, str))
    {
        if (str.size() > 0)
            result.push_back(stoi(str));
    }
    in.close();
    return result;
}

template <typename T1, typename T2>
bool find_map_value(const map<T1, T2> &m, const T2 &x)
{
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (it->second == x)
            return true;
    }
    return false;
}

tuple<int, int> count_repeat_chars(const string &str)
{
    map<char, int> m;
    for (char const &c : str)
    {
        auto x = m[c];
        m[c]++;
    };

    return make_tuple<int, int>((find_map_value<char, int>(m, 2)) ? 1 : 0, (find_map_value<char, int>(m, 3)) ? 1 : 0);
}

int string_diff(const string &str1, const string &str2)
{
    int result;
    for (int i = 0; i < str1.length(); i++)
    {
        result += (str1[i] != str2[i] ? 1 : 0);
    }
    return result;
}

/*
 * Compare two strings and return characters that are the same in both strings (i.e. same char in same position)
 */
string string_common(const string &str1, const string &str2)
{
    string result = "";
    for (int i = 0; i < str1.length(); i++)
    {
        result += (str1[i] == str2[i] ? str1[i] : '\0');
    }
    return result;
}

ptime string_to_datetime(const string &str, const string &fmt)
{
    auto dfmt = std::locale(std::locale::classic(), new time_input_facet(fmt));
    std::istringstream istr(str);
    istr.imbue(dfmt);
    ptime pt;
    istr >> pt;
    return pt;
}