#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int toilet[2][n];
    for (int i = 0; i < 2*n; i++) cin >> toilet[i/n][i%n];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (!toilet[i][j]) {
                if (j-1 >= 0 && toilet[i][j-1] == 1) continue;
                if (j+1 < n && toilet[i][j+1] == 1) continue;
                printf("(%d,%d)\n", i+1, j+1);
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}

