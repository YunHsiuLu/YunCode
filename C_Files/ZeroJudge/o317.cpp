#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string street;
        int store, b = 0;
        cin >> street;
        for (int i = 0; i < 10; i++) {
            cin >> store;
            if (store == 1) b = 1;
        }
        if (b) cout << street << endl;
    }
    return 0;
}

