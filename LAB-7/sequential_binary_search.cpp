// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

int binary_search_custom(int arr[], int left, int right, int target) 
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binary_search_custom(arr, left, mid - 1, target);

        return binary_search_custom(arr, mid + 1, right, target);
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search_custom(arr, 0, n - 1, x);

    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}