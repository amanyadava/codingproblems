/*
 * For mapping a='1', b='2', ... , z='26', count the number of ways a numeric
 * string input can be interpreted for characters. For example, '12' can be
 * interpreted in 2 ways - either "ab" or "l"
 */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

void createMappings(std::unordered_map<char, std::string>& mappings)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        uint cNum = c - 'a' + 1;
        std::stringstream ss;
        ss << cNum;
        mappings[c] = ss.str();
    }
}

int countWaysHelper(
    std::string& str,
    int idx,
    std::unordered_map<char, std::string>& mappings)
{
    if (idx == str.size())
    {
        return 1;
    }

    int count = 0;
    for (std::unordered_map<char, std::string>::iterator it = mappings.begin();
     it != mappings.end();
     it++)
    {
        if (str.compare(idx, it->second.size(), it->second) == 0)
        {
            count += countWaysHelper(str, idx + it->second.size(), mappings);
        }
    }

    return count;
}

// Uses backtracking to count the number of ways
int countWays(std::string str)
{
    std::unordered_map<char, std::string> mappings;
    createMappings(mappings);
    return countWaysHelper(str, 0, mappings);
}

// Uses DP to count the number of ways
int countWaysDP(std::string s)
{
    int len = s.size();
    if (len == 0 || s[0] == '0') return 0;

    int* table = (int*)malloc(s.size() * sizeof(int));
    table[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        table[i] = 0;
        if ((s[i] > '0') &&
            (s[i] <= '9'))
        {
            table[i] += table[i - 1];
        }

        int doubleDigits = std::stoi(s.substr(i - 1, 2));
        if ((doubleDigits > 9) &&
            (doubleDigits < 27))
        {
            table[i] += (i < 2) ? 1 : table[i - 2];
        }
    }

    int numWays = table[s.size() - 1];
    free(table);
    std::cout << "Num ways to decode \"" << s << "\" = " << numWays << "\n";
    return numWays;
}

int main(int argc, char const *argv[])
{
    countWaysDP("100");
    countWaysDP("10");
    countWaysDP("101");
    countWaysDP("111");
    countWaysDP("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565");
    return 0;
}
