#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

/*
@brief: make quardtree reverse
@pre: Set QuardTree before reverse
@post: return string of reverse quardtree
@param: iterator of quardtree _string
@return: reverse quardtree _string
*/
string ReverseQuardtree(string::iterator& iter) {				
	char head = *iter;
	iter++;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperleft = ReverseQuardtree(iter);
	string upperright = ReverseQuardtree(iter);
	string lowerleft = ReverseQuardtree(iter);
	string lowerright = ReverseQuardtree(iter);

	return string("x") + lowerleft + lowerright + upperleft + upperright;
}


int main() {
	int count;
	int num = 0;
	string input;
	cout << "Enter the Num: ";
	cin >> count;
	while (num < count) {
		cout << "Enter the quardtree: ";
		cin >> input;

		string::iterator iter;
		iter = input.begin();

		cout << "Result: " << ReverseQuardtree(iter) << endl;
		num++;
	}
}