#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, k;
        cin >> n >> k;
        if (k <= n) {
            cout << 1 << endl;
            continue;
        }
        deque<int> qu;
        int ans = n;
        for (int i = 0; i < n; i++) qu.push_back(1);
        qu.push_back(n);
        for (int i = n+2; i <= k; i++) {
            qu.push_back(ans + qu.back() - qu.front());
            qu.pop_front();
            ans = qu.back();
        }
        cout << ans << endl;
    }
    return 0;
}

