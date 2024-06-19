#include <iostream>
using namespace std;

int main() {
	int n, t1 = 0, t2 = 0, cur, pre;
	cin >> n;
	cin >> pre;
	t2++;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		if (cur > pre) {
			t1 = max(t1, t2);
			t2 = 0;
		}
		t2++;
		pre = cur;
	}
	t1 = max(t1, t2);
	cout << t1 << endl;
	return 0;
}

