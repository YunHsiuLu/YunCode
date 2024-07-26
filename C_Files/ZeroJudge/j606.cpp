#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int k, q, r;
    cin >> k >> q >> r;
    string s, t;
    cin >> s;
    t = s;
    vector<string> vec;
    int p;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < k; j++) {
            cin >> p;
            t[p-1] = s[j];
        }
        vec.push_back(t);
        s = t;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < q; j++)
            cout << vec[j][i];
        cout << endl;
    }
            
    cout << endl;
    return 0;
}

