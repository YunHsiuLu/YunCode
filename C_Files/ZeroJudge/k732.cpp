#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    int sum = 0, num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left = max(0, j-a[i][j]);
            int up = max(0, i-a[i][j]);
            for (int y = up; y <= i+a[i][j]; y++) {
                for (int x = left; x <= j+a[i][j]; x++) {
                    if (y >= n || x >= m) continue;
                    if (abs(x-j) + abs(y-i) > a[i][j]) continue;
                    sum += a[y][x];
                }
            }
            if (sum % 10 == a[i][j]) {
                num++;
                vec.emplace_back(i, j);
            }
            sum = 0;
        }
    }
    cout << num << endl;
    for (int i = 0; i < vec.size(); i++)
        printf("%d %d\n", vec[i].first, vec[i].second);
    return 0;
}

