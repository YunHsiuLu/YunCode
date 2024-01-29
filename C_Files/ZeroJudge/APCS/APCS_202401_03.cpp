#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int p=0, q=0, r=0, m=0;
	cin >> p >> q >> r >> m;
	int ANS[m+1];
	int GATE[q];
	for (int i = 1; i < p+1; i++) cin >> ANS[i];
	for (int i = 0; i < q; i++) cin >> GATE[i];
	return 0;
}

