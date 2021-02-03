#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
using namespace std;

int main(void)
{
    struct timeval TimeValue_Start;
    struct timezone TimeZone_Start;
    struct timeval TimeValue_Final;
    struct timezone TimeZone_Final;
    long time_start, time_end;
    double time_overhead;
    int i, a[10000], b[50000], c[100000],sml;
    int tid;
    //initializing array randomly
    for (i = 0; i < 10000; i++) 
    {
        a[i] = 1 + (rand() % 100000);
    }
    for (i = 0; i < 50000; i++)
    {
        b[i] = 1 + (rand() % 100000);
    }
    for (i = 0; i < 100000; i++)
    {
        c[i] = 1 + (rand() % 100000);
    }

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    sml = a[0];
#pragma omp parallel private(tid) num_threads(4)
    {
        tid = omp_get_thread_num();
#pragma omp for private(i) schedule(static)
        for (i = 0; i < 10000; ++i)
        {
            if (sml > a[i])
                sml = a[i];
        }
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in a is " << sml << "\t\tTime in Seconds (T) : " << time_overhead << endl;

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    sml = b[0];
#pragma omp parallel private(tid) num_threads(4)
    {
        tid = omp_get_thread_num();
#pragma omp for private(i) schedule(static)
        for (i = 0; i < 50000; ++i)
        {
            if (sml > b[i])
                sml = b[i];
        }
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in b is " << sml << "\t\tTime in Seconds (T) : " << time_overhead << endl;

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    sml = c[0];
#pragma omp parallel private(tid) num_threads(4)
    {
        tid = omp_get_thread_num();
#pragma omp for private(i) schedule(static)
        for (i = 0; i < 10000; ++i)
        {
            if (sml > c[i])
                sml = c[i];
        }
    }
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in c is " << sml << "\t\tTime in Seconds (T) : " << time_overhead << endl;
}