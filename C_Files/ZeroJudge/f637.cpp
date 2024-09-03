#include <iostream>
#include <string>
using namespace std;

string s;
int i = 0, area = 0;

void A(int n) {
    if (i == s.size()) return;
    for (int index = 0; index < 4; index++) {
        if (s[i] == '2') {
            i++;
            A(n/2);
        }
        else if (s[i] == '1') {
            i++;
            area += n*n;
        }
        else i++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> s >> N;
    A(N);

    cout << area << endl;
    return 0;
}

