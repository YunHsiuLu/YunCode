#include <iostream>
using namespace std;
int main() {
	int m = 0, n = 0, k = 0;
	cin >> m >> n >> k;
	// char A[m][n];
	char** A = new char* [m];
	int step[k];
	char ans[k];
	int same = 0;

	for (int i = 0; i < m; i++) {
		A[i] = new char [n];
		cin >> A[i];
	}
	for (int i = 0; i < k; i++) cin >> step[i];
	
	// From left bottom => A[m][0]
	int current_row = m-1, current_col = 0;
	for (int i = 0; i < k; i++) {
		switch (step[i]) {
			case 0:
				if (current_row-1 >= 0) current_row -= 1;
				break;
			case 1:
				if (current_col+1 < n) current_col += 1;
				break;
			case 2:
				if ((current_row+1 < m) && (current_col+1 < n)) {
					current_row += 1;
					current_col += 1;
				}
				break;
			case 3:
				if (current_row+1 < m) current_row += 1;
				break;
			case 4:
				if (current_col-1 >= 0) current_col -= 1;
				break;
			case 5:
				if ((current_row-1 >= 0) && (current_col-1 >= 0)) {
					current_row -= 1;
					current_col -= 1;
				}
				break;
			default:
				break;
		}
		ans[i] = A[current_row][current_col];
		bool check = false;
		for (int j = 0; j < i; j++) {
			if (ans[j] == A[current_row][current_col]) {
				check = true;
				break;
			}
		}
		if (!check) same++;
		cout << ans[i];
	}
	cout << endl << same;
	return 0;
}

