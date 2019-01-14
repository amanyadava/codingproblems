#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int solution(vector<int>&);
int main(int argc, char const *argv[])
{
    std::cout << "Hello World!\n";
    int candiesArray[] = {0, 0, 1, 1, 2, 3};
    vector<int> candies(candiesArray, candiesArray + sizeof(candiesArray) / sizeof(candiesArray[0]));
    cout << "Max types of candies = " << solution(candies) << "\n";
    return 0;
}

int solution(vector<int> &T)
{
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, int> typeToCount;
    for (int type : T)
    {
        if (typeToCount.end() == typeToCount.find(type))
        {
            typeToCount[type] = 1;
        }
        else
        {
            typeToCount[type]++;
        }
    }

    int nby2 = T.size() / 2;
    int candiesGiven = 0;
    bool done = false;
    for (unordered_map<int, int>::iterator it = typeToCount.begin(); it != typeToCount.end(); it++)
    {
        if (it->second > 1)
        {
            candiesGiven += it->second - 1;
            it->second = 1;
            if (candiesGiven >= nby2)
            {
                return typeToCount.size();
            }
        }
    }

    return typeToCount.size() - (nby2 - candiesGiven);
}
