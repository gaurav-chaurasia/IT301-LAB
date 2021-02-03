#include <stdio.h>
#include <omp.h>
int main()
{
    int i, n, chunk;
    int a[20], b[20], c[20];
    n = 20;
    chunk = 2;
    /*initializing array*/
    for (i = 0; i < n; i++)
    {
        a[i] = i * 2;
        b[i] = i * 3;
    }
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) num_threads(4)
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
        printf("Thread id = %d i = %d, c[%d] = %d\n", omp_get_thread_num(), i, i, c[i]);
    }
}
