/*num_threads.c*/
#include <omp.h>
#include <stdio.h>
int main()
{
#pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        printf("Hello world from thread = %d\n", tid);
    }
}
