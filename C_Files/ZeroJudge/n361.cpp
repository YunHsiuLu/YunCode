#include <iostream>
#include <cmath>
using namespace std;

bool isFullSquare(int F) {
	return pow((int)sqrt(F),2) == F;
}

int main() {
	int n, number;
	cin >> n;
	while (n--) {
		cin >> number;
		if ((number%3 == 0) && (number%2==0)) cout << 1 << " ";
		else if (((number%10)%2 == 1) && (number%3 != 0)) cout << 2 << " ";
		else if ((isFullSquare(number)) || ((number%7 != 0) && (number%2 == 0))) cout << 3 << " ";
		else cout << 0 << " ";
	}
	cout << endl;
	return 0;
}

