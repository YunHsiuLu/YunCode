#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    int N = n;
    while (N > 0) {
        total += N % 10;
        N /= 10;
    }
    if (n % total) cout << "NO" << endl;
    else cout << "YES" << endl;
	return 0;
}

