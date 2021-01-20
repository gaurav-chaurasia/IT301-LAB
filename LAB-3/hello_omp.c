#include <omp.h>
#include <stdio.h>

int main(int *argc, char *argv[]) {

    // compiler directive
    #pragma omp parallel
        printf("hello world\n");

    return 0;
}