#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
    int M, N, k;
    int i, j, x, y;
    int sum = 0;
    cin >> M >> N;

    int** matrix;
    matrix = new int* [M];
    for (int p = 0; p < M; p++) {
        matrix[p] = new int[N];
    }

    for (int p = 0; p < M; p++) {
        for (int q = 0; q < N; q++) {
            cin >> matrix[p][q];
        }
    }

    cin >> k;
    for (int z = 0; z < k; z++) {
        cin >> i >> j >> x >> y;

        for (int p = i - 1; p < x; p++) {
            for (int q = j - 1; q < y; q++) {
                sum += matrix[p][q];
            }
        }
    cout << sum << endl;
    sum = 0;
    }


    return 0;
 }