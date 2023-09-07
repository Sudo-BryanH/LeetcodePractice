#include <stdio.h>

/*
This recursive method goes down a decision tree where at every point or stair,
you can choose to take 1 or 2 steps. While correct, this implementaiton TLEs and the time
complexity is O(2^n). A better solution apparently uses some sort of dynaic programming
*/
int sum = 0;
void oneOrTwo(int curr, int n)
{
    if (curr == n)
    {
        sum += 1;
        return;
    }

    oneOrTwo(curr + 1, n);
    if (curr + 2 <= n)
    {
        oneOrTwo(curr + 2, n);
    }
}

int climbStairs(int n)
{

    oneOrTwo(0, n);
    return sum;
}

int main(int argc, char *argv[])
{

    int ans = climbStairs(44);
    printf("%d/n", ans);
}

// g++ -o code code.cpp