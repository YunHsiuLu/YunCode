#include <iostream>
using namespace std;
int main() {
    int a, b;
    while (cin >> a >> b) {
        if ((a == -1) && (b == -1)) break;
        int t1 = abs(b - a);
        int t2 = min(a, b) + 100 - max(a, b);
        printf("%d\n", min(t1, t2));
    }
    return 0;
}

