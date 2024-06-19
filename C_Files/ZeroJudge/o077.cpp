#include <iostream>
using namespace std;

int MAP[25][25];
int H, W;

int draw(int row, int col, int t, int color, int dir) {
	if (!MAP[row][col]) MAP[row][col] = color;
	else if (MAP[row][col] != color) MAP[row][col] += color;

	if (!t) return 0;

	if (row-1 >= 0 && dir != 3) draw(row-1, col, t-1, color, 1); // up: 1
	if (row+1 < H && dir != 1) draw(row+1, col, t-1, color, 3);  // down: 3
	if (col-1 >= 0 && dir != 4) draw(row, col-1, t-1, color, 2); // left: 2
	if (col+1 < W && dir != 2) draw(row, col+1, t-1, color, 4);  // right: 4
	return 0;
}

int main() {
	int step;
	cin >> H >> W >> step;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			MAP[i][j] = 0;
	
	int r, c, t, color;
	while (step--) {
		cin >> r >> c >> t >> color;
		draw(r, c, t, color, 0);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cout << MAP[i][j] << " ";
		cout << endl;
	}
	return 0;
}

