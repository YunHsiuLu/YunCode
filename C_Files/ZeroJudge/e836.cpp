#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, Max = 0;
    cin >> n;
    vector<int> nums;
    vector<int> check;
    for (int i = 0; i < n; i++) {
        int temp, b = 0;
        cin >> temp;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == temp) {
                check[j]++;
                Max = max(Max, check[j]);
                b = 1;
                break;
            }
        }
        if (b) continue;
        nums.push_back(temp);
        check.push_back(1);
    }

    cout << nums.size() << endl;
    if (Max == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (check[i] == Max)
            cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

