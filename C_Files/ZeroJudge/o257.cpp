#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer {
    int start, end, cost;
};

bool compareByEnd(const Customer &a, const Customer &b) {
    return a.end < b.end;
}

int binarySearch(const vector<Customer> &customers, int index) {
    int low = 0, high = index - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (customers[mid].end < customers[index].start) {
            if (customers[mid + 1].end < customers[index].start) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int maxIncome(vector<Customer> &customers) {
    int n = customers.size();
    
    // 按結束時間排序
    sort(customers.begin(), customers.end(), compareByEnd);
    
    // dp陣列，dp[i]表示截至第i個客戶的最大收入
    vector<int> dp(n);
    
    dp[0] = customers[0].cost;
    
    for (int i = 1; i < n; i++) {
        // 包含當前客戶的收入
        int includeCurrent = customers[i].cost;
        
        // 找到不與當前客戶衝突的上一個客戶
        int previous = binarySearch(customers, i);
        if (previous != -1) {
            includeCurrent += dp[previous];
        }
        
        // 計算dp[i]的最大值，取包含當前客戶和不包含當前客戶的最大值
        dp[i] = max(includeCurrent, dp[i - 1]);
    }
    
    // 返回最大收入
    return dp[n - 1];
}

int main() {
    int N;
    cin >> N;
    
    vector<Customer> customers(N);
    
    for (int i = 0; i < N; i++) {
        cin >> customers[i].start >> customers[i].end >> customers[i].cost;
    }
    
    cout << maxIncome(customers) << endl;
    
    return 0;
}
