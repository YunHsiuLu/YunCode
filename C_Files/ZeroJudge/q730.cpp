#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string enc = "";
    cin >> enc;
    string dec = "";
    int b = 0;
    for (auto e : enc) {
        char t;
        if ((e >= 33) && (e <= 41)) t = e+95-10;
        else t = e-10;

        if (!b) dec.append(1, t);
        else dec.insert(dec.length()-1, 1, t);
        b = !b;
    }
    cout << dec << endl;
	return 0;
}

