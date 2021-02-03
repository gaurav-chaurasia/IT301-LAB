#include <iostream>
#include <stdio.h>
#include <climits>
#include <vector>
#include <sys/time.h>

using namespace std;
#define SIZE 20

void get_randome_array(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = 1 + (rand() % 100000);
    }
}

int min_value(const vector<int> &arr) {
    int mint = INT_MAX;
    for (auto it: arr) {
        mint = min(mint, it); 
    } 
    return mint;
}

int main() {
    struct timeval TimeValue_Start;
    struct timezone TimeZone_Start;
    struct timeval TimeValue_Final;
    struct timezone TimeZone_Final;
    long time_start, time_end;
    double time_overhead;
    vector<int> ARR1(10000), ARR2(50000), ARR3(100000);

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    get_randome_array(ARR1);
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in ARR1 is " << min_value(ARR1) << "\t\tTime in Seconds (T) : " << time_overhead << endl;

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    get_randome_array(ARR2);
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in ARR2 is " << min_value(ARR2) << "\t\tTime in Seconds (T) : " << time_overhead << endl;

    gettimeofday(&TimeValue_Start, &TimeZone_Start);
    get_randome_array(ARR3);
    gettimeofday(&TimeValue_Final, &TimeZone_Final);
    time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
    time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
    time_overhead = (time_end - time_start) / 1000000.0;
    cout << "Min Value in ARR3 is " << min_value(ARR3) << "\t\tTime in Seconds (T) : " << time_overhead << endl;

    return 0;
}