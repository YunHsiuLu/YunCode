#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n=0, k=0;
    cin >> n >> k;
    int value[n];
    for (int i = 0; i < n; i++) cin >> value[i];
    sort(value, value+n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (value[i] < 0 && k > 0) {
            k -= 1;
            continue;
        }
        ans += value[i];
    }
    if (ans <= 0) ans = 0;
    cout << ans << endl;
	return 0;
}

