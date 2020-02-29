#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


void quard_tree(char** matrix, int init_low, int init_col, int N) {
    if (N != 1) {                   //matrix size if bigger than 1 beacuse of parentheses
        int sum[4] = { 0, };        //for check if matrix composed only one num
        int total_sum = 0;
        for (int i = init_low; i < init_low + N; i++) {
            for (int j = init_col; j < init_col + N; j++) {
                if (i < (init_low + (N / 2)) && j < (init_col + (N / 2))) {
                    if(matrix[i][j] == '1') sum[0] += 1;
                }
                else if (i < (init_low + (N / 2)) && j >= (init_col + (N / 2))) {
                    if (matrix[i][j] == '1') sum[1] += 1;
                }
                else if (i >= (init_low + (N / 2)) && j < (init_col + (N / 2))) {
                    if (matrix[i][j] == '1') sum[2] += 1;
                }
                else {
                    if (matrix[i][j] == '1') sum[3] += 1;
                }
            }
        }


        total_sum = sum[0] + sum[1] + sum[2] + sum[3];

        if (total_sum == 0) {       //matrix is consist of 0
            cout << '0';
        }
        else if (total_sum == pow(N, 2)) {      //matrix is consis of 1
            cout << '1';
        }
        else {                      //have to recursion
            cout << '(';
            if (sum[0] == 0) {
                cout << '0';
            }
            else if (sum[0] == pow(N / 2, 2)) {
                cout << '1';
            }
            else {
                quard_tree(matrix, init_low, init_col, N / 2);
            }

            if (sum[1] == 0) {
                cout << '0';
            }
            else if (sum[1] == pow(N / 2, 2)) {
                cout << '1';
            }
            else {
                quard_tree(matrix, init_low, init_col + (N / 2), N / 2);
            }

            if (sum[2] == 0) {
                cout << '0';
            }
            else if (sum[2] == pow(N / 2, 2)) {
                cout << '1';
            }
            else {
                quard_tree(matrix, init_low + (N / 2), init_col, N / 2);
            }

            if (sum[3] == 0) {
                cout << '0';
            }
            else if (sum[3] == pow(N / 2, 2)) {
                cout << '1';
            }
            else {
                quard_tree(matrix, init_low + (N / 2), init_col + (N / 2), N / 2);
            }
        cout << ')';
        }
    }
    else if (N == 1) {
        cout << matrix[init_low][init_col];
    }
}



int main() {
    int N;
    cin >> N;

    char** matrix;                  //allocate
    matrix = new char* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new char[N];
    }


    for (int i = 0; i < N; i++) {   //input
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    quard_tree(matrix, 0, 0, N);

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
 }