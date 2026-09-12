/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    int maxLen = 0;

    // Store first occurrence of prefix sums
    // Range of possible sums is handled using offset
    int offset = 100000;
    int size = 200001;

    int first[size];

    for (int i = 0; i < size; i++)
        first[i] = -2;

    // Sum 0 occurs before the array starts
    first[offset] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        int index = sum + offset;

        if (first[index] != -2)
        {
            int len = i - first[index];

            if (len > maxLen)
                maxLen = len;
        }
        else
        {
            first[index] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}

