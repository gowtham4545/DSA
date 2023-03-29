/*
Sort Colors
{ Amazon }

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // using counting sort
        int maxm = *max_element(nums.begin(), nums.end()); // o(n)
        vector<int> frequency(maxm + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        { // O(n)
            frequency[nums[i]]++;
        }
        int i = 0;
        int j = 0;
        while (i < maxm + 1)
        { // O(m) m=n in this case
            if (frequency[i] > 0)
            {
                nums[j++] = i;
                frequency[i]--;
            }
            else
                i++;
        }
    }
};