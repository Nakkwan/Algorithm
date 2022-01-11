#include <iostream>
using namespace std;
#define E_MAX 15
#define S_MAX 28
#define M_MAX 19

/*
pre: Asign E, S, M.
		Increasing S by max S number, check whether remainder is matched with E, M
post: return year
*/
int FindYear(int E, int S, int M) {
	int count_S = 0;
	while (1) {
		if (S % E_MAX == E) {
			if (S % M_MAX == M) {
				return S;
			}
			else {
				S += S_MAX;
				continue;
			}
		}
		S += S_MAX;
	}
}


int main() {
	int E, S, M;
	cin >> E >> S >> M;

	/*For using remainder*/
	if (E == E_MAX) {
		E = 0;
	}
	if (M == M_MAX) {
		M = 0;
	}
	cout << FindYear(E, S, M) << endl;

	return 0;
}