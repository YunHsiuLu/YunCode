#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int w1, w2, h1, h2;
    cin >> w1 >> w2 >> h1 >> h2;
    int max_height = 0;
    int layer = 1;
    int c_a = w1*w1;
    int c_h = h1;
    int c_v = c_a*c_h;
    while (n--) {
        int water;
        cin >> water;
        int temp = 0;
        while (water) {
            if (layer == 3) break;
            if (water <= c_v) {
                temp += water/c_a;
                c_v -= water;
                c_h -= temp;
                water = 0;
            }
            else if (water > c_v) {
                if (layer == 1) {
                    temp += c_h;
                    water -= c_v;
                    layer++;
                    c_a = w2*w2;
                    c_h = h2;
                    c_v = c_a*c_h;
                }
                else {
                    temp += c_h;
                    water = 0;
                    layer++;
                }
            }
        }
        max_height = max(max_height, temp);
    }
    cout << max_height << endl;
    
    return 0;
}

