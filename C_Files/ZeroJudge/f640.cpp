#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> vec;
    vector<int> num;
    string s;
    while (cin >> s) vec.push_back(s);
    while (!vec.empty()) {
        s = vec.back();
        if (s == "f") {
            int x = num.back();
            num.pop_back();
            num.push_back(2*x-3);
        }
        else if (s == "g") {
            int x = num.back();
            num.pop_back();
            int y = num.back();
            num.pop_back();
            num.push_back(2*x+y-7);
        }
        else if (s == "h") {
            int x = num.back();
            num.pop_back();
            int y = num.back();
            num.pop_back();
            int z = num.back();
            num.pop_back();
            num.push_back(3*x-2*y+z);
        }
        else {
            num.push_back(stoi(s));
        }
        vec.pop_back();
    }
    cout << num[0] << endl;
    return 0;
}

