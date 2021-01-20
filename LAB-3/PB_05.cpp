#include <stdio.h>
#include <iostream>
#include <climits>
#include <omp.h>

using namespace std;

#define SIZE 20

void get_randome_array(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 1 + (rand() % 100);
    }
}

int main()
{
    int SUM1 = 0, 
        SUM2 = 0,
        SUM3 = 0,
        SUM4 = 0;
    int arr[SIZE];
    get_randome_array(arr);
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    // shared(list)
#pragma omp parallel num_threads(1) shared(SUM1) 
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < SIZE/4; i++) {
                SUM1 += arr[i];
            }
        }
    }
#pragma omp parallel num_threads(1) shared(SUM2)
    {
        if (omp_get_thread_num() == 1) {
            for (int i = SIZE / 4; i < SIZE / 2; i++) {
                SUM2 += arr[i];
            }
        }
    }
#pragma omp parallel num_threads(1) shared(SUM3)
    {
        if (omp_get_thread_num() == 2) {
            for (int i = SIZE / 2; i < 3 * (SIZE / 4); i++) {
                SUM3 += arr[i];
            }
        }
    }
#pragma omp parallel num_threads(1) shared(SUM4)
    {
        if (omp_get_thread_num() == 3) {
            for (int i = 3 * (SIZE / 4); i < SIZE; i++) {
                SUM4 += arr[i];
            }
        }
    }
    printf("TOTAL SUM is =%d\n", SUM1 + SUM2 + SUM3 + SUM4);
}
