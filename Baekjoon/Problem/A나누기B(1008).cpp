#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	double a;
	double b;
	cin >> a >> b;
	cout << fixed << setprecision(15) << a / b << endl;


	return 0;
}