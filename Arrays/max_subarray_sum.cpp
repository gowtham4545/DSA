#include <iostream>
using namespace std;

class maximum_subarray_search
{
public:
    int best = 0;
    void algo1(int *, int);
    void algo2(int *, int);
    void algo3(int *, int);
};

// Brute Force method O(n^3):
// Going through all the possible subarrays, calculate the sum of values in each subarray and maintain the maximum sum. The variables i and j fix the first and last index of the subarray, and the sum of values is calculated to the variable sum. The variable best contains the maximum sum found during search.
void maximum_subarray_search::algo1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            best = max(best, sum);
        }
    }
    cout << best << endl;
}

// Optimising the code to O(n^2):
// Calculating the sum at the same time when the right end of the subarray moves.
void maximum_subarray_search::algo2(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            best = max(best, sum);
        }
    }
    cout << best << endl;
}

// Kadane's algorithm, O(n):
// For each array position, calculate the maximum sum of a subarray that ends at that position. After this, the answer for the problem is the maximum of those sums.
//      Consider  the subproblem of finding the maximum sum subarray that ends at position k. There are two poossibilities:
//      1. The subarray only contains the element at position k.
//      2. The subarray consists of a subarray that ends at position k-1, followed by the element at positio k.
//
//      In latter case, since we want to find a subarray with maximum sum, the subarray that ends at position k-1 should also have the maximum sum. Thus, we can solve the problem efficiently by calculating the maximum subarray sum for each ending position form left to right.
void maximum_subarray_search::algo3(int a[], int n)
{
    int sum = a[0];
    best=sum;
    for (int i = 1; i < n; i++)
    {
        sum = max(a[i], sum + a[i]);
        best = max(best, sum);
    }
    cout << best << endl;
}

int main()
{
    maximum_subarray_search m;
    int a[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    m.algo3(a, 8);
    return 0;
}