#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int face = -1; // 1: right; 2: up; 3: left; 4: down;
	int turn_left = 0, turn_right = 0, turn_back = 0;
	int pre_x = 0, pre_y = 0;
	int cur_x, cur_y;
	for (int i = 0; i < n; i ++) {
		cin >> cur_x >> cur_y;
		// 因為只有垂直或是水平的移動
		// 所以只需要判斷x是否一樣或是y是否一樣即可
		
		// 先判斷剛開始的面相
		if (i == 0) {
			if (pre_x == cur_x) {
				if (pre_y < cur_y) face = 2;
				else face = 4;
				pre_y = cur_y;
			}
			else {
				if (pre_x < cur_x) face = 1;
				else face = 3;
				pre_x = cur_x;
			}
		}
		else {
			if (pre_x == cur_x) { // 垂直移動
				if (((face == 1) && (pre_y < cur_y)) || ((face == 3) && (pre_y > cur_y))) {
					turn_left++;
					if (face == 1) face = 2;
					else face = 4;
				}
				else if (((face == 1) && (pre_y > cur_y)) || ((face == 3) && (pre_y < cur_y))) {
					turn_right++;
					if (face == 1) face = 4;
					else face = 2;
				}
				else {
					turn_back++;
					if (face == 2) face = 4;
					else face = 2;
				}
				pre_y = cur_y;
			}
			else { // 水平移動	
				if (((face == 2) && (pre_x > cur_x)) || ((face == 4) && (pre_x < cur_x))) {
					turn_left++;
					if (face == 2) face = 3;
					else face = 1;
				}
				else if (((face == 2) && (pre_x < cur_x)) || ((face == 4) && (pre_x > cur_x))) {
					turn_right++;
					if (face == 2) face = 1;
					else face = 3;
				}
				else {
					turn_back++;
					if (face == 1) face = 3;
					else face = 1;
				}
				pre_x = cur_x;
			}
		}
		//printf("face=%d; current (x,y)=(%d,%d)\n", face, pre_x, pre_y);
	}
	printf("%d %d %d\n", turn_left, turn_right, turn_back);
	return 0;
}

