#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int c = 0;
	int MAX[3] = {0, 0, 0};
	int SEC[3] = {0, 0, 0};
	int TEMP[2] = {0, 0};
	cin >> c;
	for(int i = 0; i < c; i++) {
		cin >> TEMP[0] >> TEMP[1];
		int sq = pow(TEMP[0],2) + pow(TEMP[1],2);
		if (i == 0) {
			MAX[0] = sq;
			MAX[1] = TEMP[0];
			MAX[2] = TEMP[1];
		}
		else {
			if (sq > MAX[0]) {
				for(int j = 0; j < 3; j++) SEC[j] = MAX[j];
				MAX[0] = sq;
				MAX[1] = TEMP[0];
				MAX[2] = TEMP[1];
			}
			else if (sq > SEC[0]) {
				SEC[0] = sq;
				SEC[1] = TEMP[0];
				SEC[2] = TEMP[1];
			}
			else {}
		}
	}
	cout << SEC[1] << " " << SEC[2];
	return 0;
}

