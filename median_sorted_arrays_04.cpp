#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int A_Size = nums1.size();
    int B_Size = nums2.size();

    if (A_Size > B_Size)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = A_Size;
    int half = (A_Size + B_Size + 1) / 2;

    while (low <= high)
    {
        int x_part = (low + high) / 2;
        int y_part = (half - x_part);

        int maxLeftA = x_part == 0 ? INT_MIN : nums1[x_part - 1];
        int minRightA = (x_part == A_Size) ? INT_MAX : nums1[x_part];

        int maxLeftB = y_part == 0 ? INT_MIN : nums2[y_part - 1];
        int minRightB = B_Size == y_part ? INT_MAX : nums2[y_part];

        if (minRightA >= maxLeftB && maxLeftA <= minRightB)
        {
            if ((A_Size + B_Size) % 2 == 0)
            {
                return (double)(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2;
            }
            else
            {
                return (double)max(maxLeftA, maxLeftB);
            }
        }
        else if (maxLeftA > minRightB)
        {
            high = x_part - 1;
        }
        else
        {
            low = x_part + 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> A, B;

    A.push_back(1);
    A.push_back(2);
    // A.push_back(30);A.push_back(40);A.push_back(50);
    B.push_back(3);
    B.push_back(4);
    // B.push_back(6);
    // B.push_back(35);B.push_back(60);B.push_back(65);B.push_back(70);B.push_back(75);B.push_back(85);

    cout << findMedianSortedArrays(A, B);

    return 0;
}
