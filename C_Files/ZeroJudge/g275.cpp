#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int *up, *down;
    for (int i = 0; i < n; i++) {
        int b = 0;
        up = new int[7];
        down = new int[7];
        for (int j = 0; j < 7; j++) cin >> up[j];
        for (int j = 0; j < 7; j++) cin >> down[j];
        if ((up[1] == up[3]) || (up[1] != up[5]) || (down[1] == down[3]) || (down[1] != down[5])) {
            cout << "A";
            b = 1;
        }

        if (up[6] == 0 || down[6] == 1) {
            cout << "B";
            b = 1;
        }

        if ((up[1] == down[1]) || (up[3] == down[3]) || (up[5] == down[5])) {
            cout << "C";
            b = 1;
        }
        if (b) {
            cout << endl;
            continue;
        }
        cout << "None" << endl;
    }
    return 0;
}

