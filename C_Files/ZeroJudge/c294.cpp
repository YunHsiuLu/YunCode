#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int c[3];
    for (int i = 0; i < 3; i++) cin >> c[i];
    sort(c, c+3);
    for (int i = 0; i < 3; i++) cout << c[i] << " ";
    cout << endl;
    if (c[0] + c[1] <= c[2]) printf("No\n");
    else if (c[0]*c[0] + c[1]*c[1] < c[2]*c[2]) printf("Obtuse\n");
    else if (c[0]*c[0] + c[1]*c[1] == c[2]*c[2]) printf("Right\n");
    else printf("Acute\n");
    return 0;
}

