#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int Cutter_height(int* tree, int N, long long M, int low, int hgt) {
    int mid = (low + hgt) / 2;
    if (hgt > low + 1) {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (mid - tree[i] < 0) {
                sum += tree[i] - mid;
            }
        }
        if (sum > M) {
            return Cutter_height(tree, N, M, mid, hgt);
        }
        else if (sum < M) {
            return Cutter_height(tree, N, M, low, mid);
        }
        else {
            return mid;
        }
    }
    else {
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (hgt - tree[i] < 0) {
                sum += tree[i] - hgt;
            }
        }
        if (sum >= M) {
            return hgt;
        }
        else {
            return low;
        }
    }
}


int main() {
    int N;
    long long M;
    int MAX_TREE = 1000000000;
    int MIN_TREE = 0;
    cin >> N >> M;
    int* tree;
    tree = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    cout << Cutter_height(tree, N, M, MIN_TREE, MAX_TREE) << endl;


    delete[] tree;

    return 0;
 }