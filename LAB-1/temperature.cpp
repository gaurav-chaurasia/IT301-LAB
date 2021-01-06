#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define CITY 1000
#define HOUR 24
#define READINGS 10
int tem[CITY][HOUR][READINGS];
int mean_tem[CITY][HOUR];

// generate count number of random numers between 1 to 100
void genrate_random_nums(int count) {
    int result;
    for (int i = 0; i < count; i++) {
        result = 1 + (rand() % 100);
        cout << result << " ";
    }
    cout << endl;
}

// prints the temperature information
void prind_temperature_info() {
    for (int i = 0; i < CITY; i++) {
        for (int j = 0; j < HOUR; j++) {
            cout << "[ ";
            for (int k = 0; k < READINGS; k++) {
                cout << tem[i][j][k] << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
}

void min_temperature(int count=CITY) {
    cout << "#####\tCITY NO-----MIN TEMPERATURE\t#####" << endl;
    for (int i = 0; i < min(count, CITY); i++) {
        int min_tem = INT_MAX;
        for (int j = 0; j < HOUR; j++) {
            min_tem = min(min_tem, mean_tem[i][j]);
        }
        cout << "[ 'CITY NO': " << i+1 << ", 'MIN TEMPERATURE': " << min_tem << " ]" << endl;
    }
}

void max_temperature(int count=CITY) {
    cout << "#####\tCITY NO-----MAX TEMPERATURE\t#####" << endl;
    for (int i = 0; i < min(count, CITY); i++) {
        int max_tem = INT_MIN;
        for (int j = 0; j < HOUR; j++) {
            max_tem = max(max_tem, mean_tem[i][j]);
        }
        cout << "[ 'CITY NO': " << i+1 << ", 'MAX TEMPERATURE': " << max_tem << " ]" << endl;
    }  
}

void avg_temperature(int count=CITY) {
    cout << "#####\tCITY NO-----AVG TEMPERATURE\t#####" << endl;
    for (int i = 0; i < min(count, CITY); i++) {
        float avg_tem = 0;
        for (int j = 0; j < HOUR; j++) {
            avg_tem += mean_tem[i][j];
        }
        avg_tem /= HOUR;
        cout << "[ 'CITY NO': " << i+1 << ", 'AVG TEMPERATURE': " << avg_tem << " ]" << endl;
    } 
}

int main() {
    // vector<vector<vector<int>>> tem(1000, vector<vector<int>>(24, vector<int>(10, 0)));
    // setting up the array with random data between 1 to 100;
    for (int i = 0; i < CITY; i++) {
        for (int j = 0; j < HOUR; j++) {
            for (int k = 0; k < READINGS; k++) {
                tem[i][j][k] = 1 + (rand() % 100);
            }
        }
    }

    for (int i = 0; i < CITY; i++) {
        for (int j = 0; j < HOUR; j++) {
            for (int k = 0; k < READINGS; k++) {
                mean_tem[i][j] += tem[i][j][k];
            }
            mean_tem[i][j] /= READINGS;
        }
    }

    min_temperature(7);
    max_temperature(7);
    avg_temperature(7);
    return 0;
}