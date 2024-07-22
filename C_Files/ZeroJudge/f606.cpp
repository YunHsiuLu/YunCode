#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int Q[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Q[i][j];
    
    int MIN = INT_MAX;
    while (k--) {
        int flow[55][55] = {0}, cost = 0, tt;
        for (int i = 0; i < n; i++) {
            cin >> tt;
            for (int j = 0; j < m; j++) flow[tt][j] += Q[i][j];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) cost += flow[i][j];
                else {
                    if (flow[i][j] > 1000) cost += 3000 + 2*(flow[i][j] - 1000);
                    else cost += 3*flow[i][j];
                }
            }
        }
        MIN = min(MIN, cost);
        
    }
    cout << MIN << endl;
    return 0;
}

