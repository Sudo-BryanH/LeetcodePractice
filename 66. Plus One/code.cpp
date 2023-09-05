#include <vector>

/*
REQUIRES: an integer vector/array where the first element is not 0 (no leading 0's)
MODIFIES: nothing
EFFECTS: using an array of integers that represents the digits of a large integer,
add one to the least significant digit (right-most one) and return the array of integers
representing the new number.
*/

std::vector<int> plusOne(std::vector<int> &digits)
{

    // Case of 9 at the right most digit
    if (digits[digits.size() - 1] == 9)
    {
        // loop through every digit. for every 9, turn it into a 0. if a digit isn't 9, stop this loop.
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                break;
            }
        }

        // if the greatest digit (left-most) is now 0, it means that it is the start of a new order of 10s magnitude because this is
        // a state otherwise impossible because no leading 0's. now, shift every digit to the right and add a 1
        if (digits[0] == 0)
        {
            digits.push_back(1);
            for (int i = digits.size() - 1; i >= 1; i--)
            {
                int temp = digits[i];
                digits[i] = digits[i - 1];
                digits[i - 1] = temp;
            }
        }
    }
    else // any other number at the right most digit
    {
        digits[digits.size() - 1]++;
    }

    return digits;
}
