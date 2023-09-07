#include <vector>

int removeElement(std::vector<int> &nums, int val)
{
    int diff = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            diff++;
        }
        else
        {
            nums[i - diff] = nums[i];
        }
    }

    return nums.size() - diff;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums;

    int val = *argv[0] - '0';

    for (int i = 1; i < argc; i++)
    {
        nums.push_back(*argv[i] - '0');
    }
    // g++ -o code code.cpp
    int ans = removeElement(nums, val);
    printf("%d/n", ans);
}