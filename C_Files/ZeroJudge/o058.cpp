#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
vector<int> dp(MAX_N + 1, INT_MAX);

bool isDirectInput(int n) {
    string s = to_string(n);
    return s.length() <= 4 && s.find_first_not_of("789") == string::npos;
}

void precompute() {
    queue<pair<int, int>> q;
    
    // Handle direct inputs
    for (int i = 1; i <= MAX_N; ++i) {
        if (isDirectInput(i)) {
            dp[i] = to_string(i).length();
            q.push({i, dp[i]});
        }
    }

    while (!q.empty()) {
        int curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (int digit : {7, 8, 9}) {
            vector<pair<int, char>> operations = {{curr + digit, '+'}, {curr - digit, '-'}, {curr * digit, '*'}};
            if (digit != 0) operations.push_back({curr / digit, '/'});

            for (auto [next, op] : operations) {
                if (next >= 0 && next <= MAX_N) {
                    int newSteps = steps + 2;  // +1 for digit, +1 for operation/=
                    if (dp[next] > newSteps) {
                        dp[next] = newSteps;
                        q.push({next, newSteps});
                    }
                }
            }
        }
    }
}

int main() {
    precompute();

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}
