#include <iostream>
#include <vector>

int FirstMissing(std::vector<int>& integers)
{
    int j = integers.size() - 1;
    for (int i = integers.size() - 1; i >=0; i--)
    {
        if (integers[i] < 1)
        {
            std::swap(integers[i], integers[j]);
            j--;
        }
    }

    for (int i = 0; i <= j; i++)
    {
        if (std::abs(integers[i]) <= j + 1)
        {
            if (integers[std::abs(integers[i]) - 1] > 0)
            {
                integers[std::abs(integers[i]) - 1] *= -1;
            }
        }
    }

    for (int i = 0; i <= j; i++)
    {
        if (integers[i] > 0)
        {
            return i + 1;
        }
    }

    return j + 2;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
