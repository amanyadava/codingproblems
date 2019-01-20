/* For a given list of integers, find the maximum sum of non adjacent numbers
 * in the list.
 */

#include <iostream>
#include <vector>

#define CallMaxSumNonAdjacent(list) \
std::cout << "Max sum of non adjacent numbers in " #list << " = " << \
MaxSumNonAdjacent(list) << "\n";

int MaxSumNonAdjacent(std::vector<int> list)
{
    if (list.size() == 0)
    {
        return 0;
    }

    int prevMaxSumWithCur = 0, prevMaxSumWoCur = 0;
    int maxSumWithCur, maxSumWoCur;
    for (int num : list)
    {
        maxSumWoCur = std::max(prevMaxSumWithCur, prevMaxSumWoCur);
        maxSumWithCur = prevMaxSumWoCur + ((num > 0) ? num : 0);

        prevMaxSumWithCur = maxSumWithCur;
        prevMaxSumWoCur = maxSumWoCur;
    }

    return std::max(maxSumWithCur, maxSumWoCur);
}

int main(int argc, char const *argv[])
{
    std::vector<int> firstTest{ 2, 4, 6, 2, 5 };
    std::vector<int> secondTest{ 5, 1, 1, 5 };
    std::vector<int> thirdTest{ 5, -1, -1, -5 };
    std::vector<int> fourthTest{ 5, 1, -1, -5 };
    std::vector<int> fifthTest{ 5, -1, 1, -5 };
    std::vector<int> sixthTest{ 5, -1, -1, -5, 2 };
    CallMaxSumNonAdjacent(firstTest);  // Expected 13
    CallMaxSumNonAdjacent(secondTest); // Expected 10
    CallMaxSumNonAdjacent(thirdTest);  // Expected 5
    CallMaxSumNonAdjacent(fourthTest); // Expected 5
    CallMaxSumNonAdjacent(fifthTest);  // Expected 6
    CallMaxSumNonAdjacent(sixthTest);  // Expected 7
    return 0;
}
