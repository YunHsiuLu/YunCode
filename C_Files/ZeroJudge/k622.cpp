#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, K;
    cin >> n >> K;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n; i++) cin >> values[i];

    map<int, int> dp;
    dp[0] = 0; // initial weight = 0, with 0 value

    for (int i = 0; i < n; i++) {
        printf("the %d-th thing:\n", i+1);
        map<int, int> new_dp = dp;
        for (auto& [weight, value] : dp) {
            printf("\t[weight, value] = [%d, %d]\t", weight, value);
            int new_weight = weight + weights[i];
            int new_value = value + values[i];
            printf("[new_weight, new_value] = [%d, %d]\n", new_weight, new_value);
            if (new_weight <= K) {
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

