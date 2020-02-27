#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void stair_num(int N, int** storage) {
    if (N == 1) {
        storage[0][1] = 0;
        for (int i = 1; i < 10; i++) {
            storage[i][1] = 1;
        }
    }
    else if (N == 2) {
        for (int i = 1; i < 9; i++) {
            storage[i][2] = 2;
        }
        storage[9][2] = 1;
        storage[0][2] = 1;
    }
    else {
        if (storage[1][N - 1] == 0) {
            stair_num(N - 1, storage);
        }
        for (int i = 1; i < 9; i++) {
            /*Do remainder operator to avoid overflow*/
            storage[i][N] = (storage[i - 1][N - 1] + storage[i + 1][N - 1]) % 1000000000;
        }
        storage[9][N] = storage[8][N - 1];
        storage[0][N] = storage[1][N - 1];
    }
}

int main() {
    int N;
    long long sum = 0;
    cin >> N;

    int** storage;                  //allocate N digits start with i
    storage = new int* [10];
    for (int i = 0; i < 10; i++) {
        storage[i] = new int[N + 1];
    }

    for (int i = 0; i < 10; i++) {  //initialize
        for (int j = 0; j < N + 1; j++) {
            storage[i][j] = 0;
        }
    }

    stair_num(N, storage);

    for (int i = 1; i < 10; i++) {
        sum += storage[i][N];
    }

    cout << sum % 1000000000 << endl;

    return 0;
 }