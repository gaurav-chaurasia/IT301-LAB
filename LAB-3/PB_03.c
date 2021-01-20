#include <stdio.h>
#include <omp.h>
int main()
{
    int a = 10;
//default(shared/none) private(list)  firstprivate(list) shared(list)
#pragma omp parallel num_threads(4) shared(a)
    {
        a = a + 20;
        int tid = omp_get_thread_num();
        printf("Hello world from thread=%d value of a=%d\n", tid, a);
    }
    printf("After parallel loop a=%d\n", a);
}
