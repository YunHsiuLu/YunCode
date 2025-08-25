#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, P;
    cin >> n >> P;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    
    map<int, int> dp;
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        map<int, int> new_dp = dp;
        for (auto& [weight, value] : dp) {
            int new_weight = weight + A[i];
            int new_value = value + A[i];

            if (new_weight <= P) {
                if (new_dp.find(new_weight) == new_dp.end()) {
                    new_dp[new_weight] = new_value;
                }
                else {
                    new_dp[new_weight] = max(new_dp[new_weight], new_value);
                }
            }
        }
        dp = new_dp;
    }

    int max_value = 0;
    for (auto& [weight, value] : dp) {
        max_value = max(max_value, value);
    }
    cout << max_value << endl;
	return 0;
}

