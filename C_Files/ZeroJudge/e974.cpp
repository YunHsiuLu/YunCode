#include <iostream>
using namespace std;
int main() {
    int R, C, N;
    cin >> R >> C >> N;
    int MAP[R+1][C+1];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            MAP[i][j] = (j+1) + i*C;
        }
    }
    for (int w = 2; w <= N; w++) {
        if (w % 2 == 0) {
            for (int i = 0; i < R; i++) {
                for (int j = C-1; j >= 0; j--) {
                    MAP[i][j+1] = MAP[i][j];
                }
                MAP[i][0] = MAP[i][C];
            }
        }
        else {
            for (int j = 0; j < C; j++) {
                for (int i = R-1; i >= 0; i--) {
                    MAP[i+1][j] = MAP[i][j];
                }
                MAP[0][j] = MAP[R][j];
            }
        }
    }

    for (int i = 0; i < R-1; i++) {
        for (int j = 0; j < C-1; j++) {
            printf("%d ", MAP[i][j]);
        }
        printf("%d\n", MAP[i][C-1]);
    }
    for (int j = 0; j < C-1; j++) {
        printf("%d ", MAP[R-1][j]);
    }
    printf("%d", MAP[R-1][C-1]);
    return 0;
}

