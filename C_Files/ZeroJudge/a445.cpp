#include <iostream>
using namespace std;

int p[10001], r[10001];

int Find(int x) {
    return (p[x] == -1 ? x : p[x] = Find(p[x]));
}

void Joint(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;

    if (r[x] > r[y]) {
        r[x] += r[y];
        p[y] = x;
    }
    else {
        r[y] += r[x];
        p[x] = y;
    }
}

int main() {
    int n, m, q, x, y;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        p[i] = -1;
        r[i] = 1;
    }

    while (m--) {
        cin >> x >> y;
        Joint(x, y);
    }

    while (q--) {
        cin >> x >> y;
        if (Find(x) == Find(y)) cout << ":)" << endl;
        else cout << ":(" << endl;
    }
    return 0;
}

