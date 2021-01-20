#include <stdio.h>
#include <omp.h>
int main()
{
    int p = 1;
#pragma omp parallel if (p == 1) num_threads(4)
    {
        int tid = omp_get_thread_num();
        printf("Hello world from thread=%d\n", tid);
    }
}
