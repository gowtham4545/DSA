// Minimize the Maximum of Two Arrays

/*
We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
No integer is present in both arr1 and arr2.
Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        ll l = 1, r = 1e15, ans = r, d1 = divisor1, d2 = divisor2, cnt1 = uniqueCnt1, cnt2 = uniqueCnt2;
        ll g = __gcd(d1, d2), lcm = (d1 * d2) / g;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            // c1 -> integers that are divisible by d1 only
            // c2 -> integers that are divisible by d2 only
            ll common = mid / lcm;
            ll c1 = (mid / d1) - common, c2 = (mid / d2) - common;

            ll z1 = cnt1, z2 = cnt2;
            ll avail = mid - (c1 + c2 + common); // No of elements that can be filled in both the arrays
            z1 -= min(z1, c2);
            z2 -= min(z2, c1);

            if (z1 + z2 <= avail)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    return 0;
}