#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long ans = 0;
int N, K;

void A(const vector<int>& v, int deep) {
    int size = v.size();
    if (size < 3 || deep >= K) return;

    vector<long long> left_sum(size, 0);
    long long total = 0;
    for (int i = 1; i < size; i++) {
        total += v[i - 1];
        left_sum[i] = left_sum[i - 1] + total;
    }

    vector<long long> right_sum(size, 0);
    total = 0;
    for (int i = size - 2; i >= 0; i--) {
        total += v[i + 1];
        right_sum[i] = right_sum[i + 1] + total;
    }

    int cut_pos = -1;
    long long min_diff = LLONG_MAX;
    for (int i = 1; i < size - 1; i++) {
        long long diff = abs(left_sum[i] - right_sum[i]);
        if (diff < min_diff) {
            min_diff = diff;
            cut_pos = i;
        }
    }

    ans += v[cut_pos];

    vector<int> left_subarray(v.begin(), v.begin() + cut_pos);
    vector<int> right_subarray(v.begin() + cut_pos + 1, v.end());

    A(left_subarray, deep + 1);
    A(right_subarray, deep + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<int> vec(N);
    for (int &x : vec) {
        cin >> x;
    }

    A(vec, 0);
    cout << ans << endl;

    return 0;
}
