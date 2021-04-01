#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;

#define MAX1 500000

int binary_search(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int array[MAX1];
    int loc, loc1, loc2, loc3, loc4, k;
    omp_set_num_threads(4);

    for (int i = 0; i < MAX1; ++i)
        array[i] = rand() % 1000;

    sort(array, array + MAX1);

    cout << "Enter number to search : ";
    cin >> k;
    int mid = MAX1 / 2;
    double start_time = omp_get_wtime();
    loc1 = binary_search(array, k, 0, mid);
    loc2 = binary_search(array, k, mid + 1, MAX1 - 1);
    double end_time = omp_get_wtime() - start_time;
    cout << loc1 << "\t" << loc2 << endl;
    cout << "Sequential Binary search runtime : " << end_time << endl;

    int one_quart = mid / 2;
    int three_quart = 3 * one_quart;
    start_time = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        loc1 = binary_search(array, k, 0, one_quart);
#pragma omp section
        loc2 = binary_search(array, k, one_quart + 1, mid);
#pragma omp section
        loc3 = binary_search(array, k, mid + 1, three_quart);
#pragma omp section
        loc4 = binary_search(array, k, three_quart + 1, MAX1 - 1);
    }
    end_time = omp_get_wtime() - start_time;
    cout << loc1 << "\t" << loc2 << "\t" << loc3 << "\t" << loc4 << endl;
    cout << "Parallel Binary search runtime : " << end_time << endl;
}