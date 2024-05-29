#include <iostream>
using namespace std;

int main() {
	int R, C, k, m;
	cin >> R >> C >> k >> m;
	int pre_MAP[R][C], MAP[R][C];
	int MAX = -99999, MIN = 99999;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> pre_MAP[i][j];
	}
	int leave = 0, come = 0;
	while (m--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				leave = 0;
				come = 0;
				if (pre_MAP[i][j] == -1) {
					MAP[i][j] = -1;
					continue;
				}
				if ((j-1 >= 0) && !(pre_MAP[i][j-1] == -1)) {
					come  += pre_MAP[i][j-1]/k;
					leave += pre_MAP[i][j]/k;
				}
				if ((j+1 < C)  && !(pre_MAP[i][j+1] == -1)) {
					come  += pre_MAP[i][j+1]/k;
					leave += pre_MAP[i][j]/k;
				}
				if ((i-1 >= 0) && !(pre_MAP[i-1][j] == -1)) {
					come  += pre_MAP[i-1][j]/k;
					leave += pre_MAP[i][j]/k;
				}
				if ((i+1 < R)  && !(pre_MAP[i+1][j] == -1)) {
					come  += pre_MAP[i+1][j]/k;
					leave += pre_MAP[i][j]/k;
				}
				MAP[i][j] = pre_MAP[i][j] - leave + come;
				//cout << MAP[i][j] << endl;
			}
		}
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << MAP[i][j] << " ";
				if (MAP[i][j] == -1) continue;
				if (MAP[i][j] > MAX) MAX = MAP[i][j];
				if (MAP[i][j] < MIN) MIN = MAP[i][j];
			}
			cout << endl;
		}
	}
	printf("%d\n%d\n", MIN, MAX);
	return 0;
}

