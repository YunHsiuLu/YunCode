#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    int *q;
    int num = 0,cost = 0;
    for (int i = 0; i < n; i++) {
        q = new int[3];
        for (int j = 0; j < 3; j++) cin >> q[j];
        sort(q, q+3);
        if (q[2] - q[0] >= d) {
            num++;
            cost += (q[0]+q[1]+q[2])/3;
        }
        else continue;
    }
    printf("%d %d\n", num, cost);
    return 0;
}

