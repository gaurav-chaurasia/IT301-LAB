#include <stdio.h>
#include <omp.h>
int main()
{
    int N = 20, a[20], b[20], c[20];
    int low, high, i;
    // initialize array elements
    for (i = 0; i < N; i++)
    {
        b[i] = i;
        c[i] = i * 2;
    }
#pragma omp parallel num_threads(4) private(low, high)
    {
        int tid = omp_get_thread_num();
        int numthreads = omp_get_num_threads();
        //distribute the work among threads
        low = N * tid / numthreads;
        high = N * (tid + 1) / numthreads;
        printf(" thread=%d low=%d high=%d \n", tid, low, high);
        //perform operation
        for (i = low; i < high; i++)
        {
            a[i] = b[i] + c[i];
            printf("addition from thread=%d value of a[%d]= %d \t b[%d]=%d \t c[%d]=%d\n", tid, i, a[i], i, b[i], i, c[i]);
        }
    }
}
