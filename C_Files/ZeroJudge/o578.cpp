#include <iostream>
using namespace std;
int main() {
    int L, H, W, K;
    cin >> L >> H >> W >> K;
    if (L % K != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (H % K != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (W % K != 0) {
        cout << 0 << endl;
        return 0;
    }

    int l = L/K, h = H/K, w = W/K;
    cout << l*h*w << endl;
    return 0;
}

