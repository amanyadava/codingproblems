/* You are given an input list of non negative integers. The element at each
 * index specifies the maximum size of jump you can make ahead in the list.
 * Find the minimum number of jumps it takes to reach the last index of the
 * list.
 */

#include <iostream>
#include <vector>

#define CALL_MIN_JUMPS(list) \
std::cout << "Min number of jumps to end for " #list << " = " << \
MinJumpsToReachEnd(list) << "\n"; 

// This function finds the minimim number of jumps needed to get to the last
// element of the input vector.
// -"curStep" follows the elements to be jumped to in order to reach the last
//      element in the minimum number of jumps.
// -"furthestJump" keeps track of the maximum element index reached via jumps
//      from previos step. Hence it starts from 0 initially.
// -"furthestJumpAtNextStep" saves the furthest jump that can be made in the
//      range (furthestJump, curStep + nums[curStep])
// -"nextStep" is the next step to maximize jump range.
int MinJumpsToReachEnd(std::vector<int>& nums)
{
    if (nums.size() < 2 ||
        nums[0] == 0)
    {
        return 0;
    }

    int furthestJump = 0, numJumps = 0;
    int curStep = 0;
    while (curStep < nums.size())
    {
        int furthestJumpAtNextStep = 0, nextStep;
        for (int idx = furthestJump + 1; idx <= curStep + nums[curStep] && idx < nums.size(); idx++)
        {
            if (idx + nums[idx] > furthestJumpAtNextStep)
            {
                furthestJumpAtNextStep = idx + nums[idx];
                nextStep = idx;
            }
        }

        if (furthestJumpAtNextStep > furthestJump)
        {
            furthestJump = curStep + nums[curStep];
            curStep = nextStep;
            numJumps++;
        }
        else
        {
            return 0;
        }

        if (furthestJump >= nums.size() - 1)
        {
            break;
        }
    }

    return numJumps;
}

int main(int argc, char const *argv[])
{
    std::vector<int> firstTest = { 2,3,1,1,4 };
    std::vector<int> secondTest = { 2,0,2,0,1 };
    std::vector<int> thirdTest = { 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };
    CALL_MIN_JUMPS(firstTest);
    CALL_MIN_JUMPS(secondTest);
    CALL_MIN_JUMPS(thirdTest);
    return 0;
}
