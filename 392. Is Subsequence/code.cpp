#include <string>

/*
REQUIRES: two strings where s.size() < t.size()
MODIFIES: nothing
EFFECTS: returns true if s' letters are in t in the order that s' letters show up in. false otherwise
*/
bool isSubsequence(std::string s, std::string t)
{
    // To keep track of the current index of s that has yet to be found in t in order
    int curr = 0;

    // in this loop, if curr is not larger than the size of s (unneessary but will have to change the code below to >=) and the letters at i for t and
    // curr for s match, increase curr by one and move on
    for (int i = 0; i < t.size(); i++)
    {
        if (curr < s.size() && (char)s[curr] == (char)t[i])
            curr++;
    }
    // if curr is the size of s (presuming that all letters of s are accounted for and therefore is a subsequence), then true
    return (curr == s.size()) ? true : false;
}

int main()
{
    std::string s = "abc", t = "ahbgdc";
    std::string sf = "ade", tf = "ahbgdc";

    printf("%s\n", isSubsequence(s, t) ? "true" : "false");
    printf("%s\n", isSubsequence(sf, tf) ? "true" : "false");
}