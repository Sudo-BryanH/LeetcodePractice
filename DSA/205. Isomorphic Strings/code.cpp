#include <map>
#include <string>

/*
REQUIRES: s and t are strings of the same size
MODIFIES: nothing
EFFECTS: returns true if s and t are isomorphic. That is, every letter in s can be replaced by a different letter to
construct t (and every single one of the same letters in s will be replaced by the same one)
*/
bool isIsomorphic(std::string s, std::string t)
{

    std::map<char, char> comparator;
    std::map<char, char> comparator2;

    /*
    For every letter in t, t[i] will either add the corresponding letter from s, s[i] as a pair to comparator,
    or will make sure that that comparator[t[i]] is not different s[i] at index i. If they are different, then that
    means that it doesn't follow the same pattern and therefore cannot be isomorphically replaced

    */
    for (int i = 0; i < s.size(); i++)
    {
        if (comparator.count(t[i]) == 0)
        {

            comparator[t[i]] = s[i];
        }
        else
        {
            if (comparator[t[i]] != s[i])
                return false;
        }
    }

    // Will go through two passes to ensure each character maps to only one other character exclusively. This time, will compare s to t

    for (int i = 0; i < s.size(); i++)
    {
        if (comparator2.count(s[i]) == 0)
        {

            comparator2[s[i]] = t[i];
        }
        else
        {
            if (comparator2[s[i]] != t[i])
                return false;
        }
    }

    return true;
}
