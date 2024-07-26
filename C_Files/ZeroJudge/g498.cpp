#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x < c/a+1; x++) {
        for (int y = 0; y < c/b+1; y++) {
            if (a*x + b*y > c) continue;
            if (a*x + b*y == c) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

