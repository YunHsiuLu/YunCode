#include <iostream>
using namespace std;
int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    unsigned long a, b;
    while () {
        cin >> a >> b;
        int count=0;
        while (a != b) {
            a >>= 1;
            b >>= 1;
            count++;
        }
        cout << (a << count) << endl;
    }
	return 0;
}

