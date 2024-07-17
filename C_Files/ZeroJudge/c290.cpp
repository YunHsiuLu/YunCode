#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string n;
    cin >> n;
    int ans = 0;
    int b = 0;
    for (int i = 0; i < n.size(); i++) {
        ans += (n[i] - '0')*(int)pow(-1, b);
        b = !b;
    }
    cout << abs(ans) << endl;
    return 0;
}

