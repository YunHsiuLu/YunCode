#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        double ans = 0.;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                ans += i * log10(j+1-i);
            }
        }
        printf("%d\n", (int)floor(ans) + 1);
    }
    return 0;
}
