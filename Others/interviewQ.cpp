
#include <iostream>
#include <string>
using namespace std;

string printNumPrimes(string s)
{

    string nStr = "";
    string mStr = "";
    int commaIdx = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ((char)s[i] == ',')
        {
            commaIdx = i;
            break;
        }
    }

    for (int i = 0; i < commaIdx; i++)
    {
        nStr += s[i];
    }

    int n = stoi(nStr);

    for (int i = commaIdx + 1; i < (int)s.size(); i++)
    {
        mStr += s[i];
    }

    int m = stoi(mStr);

    int ans = 0;

    for (int i = n; i <= m; i++)
    {
        bool prime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                prime = false;
        }
        if (prime)
        {
            ans++;
            printf("%d", i);
        }
    }
    cout << to_string(ans) << endl;
    // For some reason cout won't print this string (or any string) after the for loop
    return to_string(ans);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << printNumPrimes(line) << endl;
    }
}
