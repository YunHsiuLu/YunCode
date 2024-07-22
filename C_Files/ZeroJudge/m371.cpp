#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int MAP[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    int check = 1, score = 0;
    while (check) {
        check = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (MAP[i][j] != -1) {
                    for (int k = i+1; k < n; k++) {
                        if (MAP[k][j] == MAP[i][j] && MAP[k][j] != -1) {
                            check = 1;
                            score += MAP[i][j];
                            MAP[i][j] = -1;
                            MAP[k][j] = -1;
                            break;
                        }
                        if (MAP[k][j] != -1) break;
                    }
                    for (int k = j+1; k < m; k++) {
                        if (MAP[i][k] == MAP[i][j] & MAP[i][k] != -1) {
                            check = 1;
                            score += MAP[i][j];
                            MAP[i][j] = -1;
                            MAP[i][k] = -1;
                            break;
                        }
                        if (MAP[i][k] != -1) break;
                    }
                }
            }
        }
    }
    cout << score << endl;

    return 0;
}

