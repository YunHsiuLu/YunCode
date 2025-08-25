#include <iostream>
#include <string>
using namespace std;

int main() {
    string OP;
    cin >> OP;
    int R, C;
    cin >> R >> C;
    int A[101][101];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> A[i][j];
    if (OP == "TRANSPOSE") {
        printf("%d %d\n", C, R);
        for (int j = 0; j < C; j++) {
            for (int i = 0; i < R-1; i++) {
                printf("%d ", A[i][j]);
            }
            printf("%d\n", A[R-1][j]);
        }
    }
    else {
        int B[101][101];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> B[i][j];
         printf("%d %d\n", R, C);
         if (OP == "ADD") {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C-1; j++) {
                    printf("%d ", A[i][j] + B[i][j]);
                }
                printf("%d\n", A[i][C-1] + B[i][C-1]);
            }
         }
         else if (OP == "SUB") {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C-1; j++) {
                    printf("%d ", A[i][j] - B[i][j]);
                }
                printf("%d\n", A[i][C-1] - B[i][C-1]);
            }
         }
         else if (OP == "MUL") {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C-1; j++) {
                    printf("%d ", A[i][j] * B[i][j]);
                }
                printf("%d\n", A[i][C-1] * B[i][C-1]);
            }
         }
    }
	return 0;
}

