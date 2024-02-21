#include <iostream>
using namespace std;

const int SIZE = 1005;
int MAP[SIZE][SIZE], temp_MAP[SIZE][SIZE];

int count_MAP(int h, int w) {
    int temp = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            temp += MAP[i][j];
        }
    }
    return temp;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int H, W, K;
    cin >> H >> W >> K;
    int c = 0, cl = 0, cg = 0;
    int first_day = 0;
    while (c < H) {
        for(int i = 0; i < W; i++) {
            cin >> MAP[c][i];
            first_day += MAP[c][i];
        }
        c++;
    }
    int temp = 0;
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                c = 0;
                cl = 0;
                cg = 0;
                if ((j+1 < W)) {
                    c++;
                    if (MAP[i][j] > MAP[i][j+1]) cl++;
                    else if (MAP[i][j] < MAP[i][j+1]) cg++;
                }
                if ((j-1 >= 0)) {
                    c++;
                    if (MAP[i][j] > MAP[i][j-1]) cl++;
                    else if (MAP[i][j] < MAP[i][j-1]) cg++;
                }
                if ((i-1 >= 0)) {
                    c++;
                    if (MAP[i][j] > MAP[i-1][j]) cl++;
                    else if (MAP[i][j] < MAP[i-1][j]) cg++;

                }
                if ((i+1 < H)) {
                    c++;
                    if (MAP[i][j] > MAP[i+1][j]) cl++;
                    else if (MAP[i][j] < MAP[i+1][j]) cg++;
                }
                if (cl > (float)c/2) temp_MAP[i][j] = MAP[i][j]-1;
                else if (cg > (float)c/2) temp_MAP[i][j] = MAP[i][j]+1;
                else temp_MAP[i][j] = MAP[i][j];
            }
        }
        cout << endl;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                MAP[i][j] = temp_MAP[i][j];
    }
    cout << count_MAP(H, W) - first_day << endl;
    
	return 0;
}

