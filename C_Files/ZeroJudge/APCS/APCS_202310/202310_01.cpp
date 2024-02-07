#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x = 0, n = 0;
    cin >> x >> n;
    int input[n+1];
    for (int i = 0; i < n; i++) cin >> input[i];
    input[n] = x;
    sort(input, input+n+1);
    int c = 0;
    while (input[c] != x) c++;
    if (c > n/2) cout << c << " " << input[0];
    else cout << n-c << " " << input[n];
    cout << endl;

	return 0;
}

