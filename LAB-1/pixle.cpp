#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define GRID 256
int pixle[GRID][GRID];
vector<string> pixle_hex; // for storing hex conversion
// 00, 01, 02, .... , FD, FE, FF 

void generate_hex() {
    char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E' , 'F' };
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            string str = "\0";
            str.push_back(hex[i]);
            str.push_back(hex[j]);
            pixle_hex.push_back(str);
        }
    }
    sort(pixle_hex.begin(), pixle_hex.end());
}

// prints the temperature information
void prind_pixle_grid(int max_row=GRID, int max_col=GRID) {
    for (int i = 0; i < min(max_row, GRID); i++) {
        for (int j = 0; j < min(max_col, GRID); j++) {
            cout << pixle_hex[pixle[i][j]] << "   ";
        }
        cout << endl;
    }
}

void inc_pixle(int count) {
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            pixle[i][j] = min(255, pixle[i][j] + count);
        }
    }
}
int main() {
    generate_hex();

    // setting up the array with random data between 0 to 255;
    for (int i = 0; i < GRID; i++) {
        for (int j = 0; j < GRID; j++) {
            pixle[i][j] = (rand() % 256);
        }
    }
    prind_pixle_grid(20, 20);
    inc_pixle(20);
    return 0;
}