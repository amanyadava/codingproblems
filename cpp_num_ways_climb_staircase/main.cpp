/* Given an input length of staircase, find the number of unique ways you can
 * climb the flight of stairs if you can only climb 1 or 2 stairs in each step.
 */

#include <iostream>

// This comes out to be the same as fibonacci series
int NumWaysStaircase(int n)
{
    if (n < 2)
    {
        return std::max(n, 0);
    }
    int waysLastStep1 = 1, waysLastStep2 = 0;
    for (int i = 1; i < n; i++)
    {
        // int curWaysLastStep1 = waysLastStep2 + waysLastStep1;
        // int curWaysLastStep2 = waysLastStep1;

        // waysLastStep1 = curWaysLastStep1;
        // waysLastStep2 = curWaysLastStep2;

        // This does the same thing as above
        waysLastStep1 += waysLastStep2;
        waysLastStep2 = waysLastStep1 - waysLastStep2;
    }

    return waysLastStep1 + waysLastStep2;
}

int main(int argc, char const *argv[])
{
    std::cout << NumWaysStaircase(4) << "\n";
    // Overflows after 45
    std::cout << NumWaysStaircase(45) << "\n";
    return 0;
}
