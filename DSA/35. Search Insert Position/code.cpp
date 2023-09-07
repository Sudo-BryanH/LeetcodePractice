#include <vector>

int searchInsert(std::vector<int> &nums, int target)
{

    int min = 0;
    int max = nums.size() - 1;
    int start = max / 2;

    while (min <= max)
    {

        if (min == max)
        {
            if (target <= nums[min])
                return min;
            else
                return max + 1;
        }

        if (max - min == 1)
        {
            if (target <= nums[min])
                return min;
            else
            {

                min++;
                start = min;
                continue;
            }
        }

        if (nums[start] == target)
            return start;
        else if (nums[start] < target)
        {
            min = start + 1;
            start = min + (int)(max - min) / 2;
        }
        else if (nums[start] > target)
        {
            max = start - 1;
            start = min + (int)(max - min) / 2;
        }
    }

    return -1;
}