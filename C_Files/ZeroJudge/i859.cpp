#include <iostream>
using namespace std;
int main() {
    int n, i = 1;
    cin >> n;
    
    while (i <= n) {
        long long x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        long long start_layer = x0+y0;
        long long end_layer = x1+y1;
        long long start_step = start_layer * (start_layer+1) / 2;
        long long end_step = end_layer * (end_layer+1) / 2;
        long long start2end = end_step - start_step;
        start2end += (end_layer - y1) - (start_layer - y0);
        printf("Case %d: %lld\n", i, start2end);
        i++;
    }
    return 0;
}

