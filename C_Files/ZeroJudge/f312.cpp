#include <iostream>
using namespace std;
int main() {
    int A1, B1, C1, A2, B2, C2, n;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2 >> n;
    int MAX = -9999, Y1, Y2, x2;
    for (int x1 = 0; x1 <= n; x1++) {
        x2 = n - x1;
        Y1 = A1*x1*x1 + B1*x1 + C1;
        Y2 = A2*x2*x2 + B2*x2 + C2;
        MAX = max(MAX, Y1+Y2);
    }
    cout << MAX << endl;
    return 0;
}

