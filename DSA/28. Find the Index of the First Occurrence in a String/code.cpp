xq#include <string>

/*
This solution is a brute force method that goes through the whole haystack and compares the substring
in haystack from letter i to i + needle.size. If it finds one, it immediately returns i. This works in O(n) time
*/
int strStr(std::string haystack, std::string needle)
{
    for (int i = 0; i < haystack.size(); i++)
    {

        if (needle == haystack.substr(i, needle.size()))
        {
            return i;
        }
    }

    return -1;
}
