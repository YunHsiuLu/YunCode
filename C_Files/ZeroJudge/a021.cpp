#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string a, m, b;
    cin >> a >> m >> b;
    vector<int> vec;
    if (m == "+") {
        int dig = max(a.size(), b.size());
        for (int i = 0; i < dig; i++) {
            if (i >= a.size()) vec.push_back(b[b.size()-i-1]-'0');
            else if (i >= b.size()) vec.push_back(a[a.size()-i-1]-'0');
            else vec.push_back((a[a.size()-i-1]-'0') + (b[b.size()-i-1]-'0'));
        }
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] >= 10) {
                vec[i+1] += vec[i]/10;
                vec[i] %= 10;
            }
        }
        if (vec[vec.size()-1] >= 10) {
            vec.push_back(vec[vec.size()-1]/10);
            vec[vec.size()-2] %= 10;
        }
    }
    else if (m == "-") {
        int dig = max(a.size(), b.size());
        for (int i = 0; i < dig; i++) {
            if (i >= a.size()) vec.push_back(-(b[b.size()-i-1]-'0'));
            else if (i >= b.size()) vec.push_back(a[a.size()-i-1]-'0');
            else vec.push_back((a[a.size()-i-1]-'0') - (b[b.size()-i-1]-'0'));
        }
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] < 0) {
                vec[i+1] -= 1;
                vec[i] += 10;
            }
        }
        if (vec[vec.size()-1] < 0) {
            vec[vec.size()-1] += 10;
            vec.push_back('-');
        }
    }
    else if (m == "*") {
        int d = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                d = i+j;
                if (d >= vec.size())
                    vec.push_back((a[a.size()-i-1]-'0') * (b[b.size()-j-1]-'0'));
                else {
                    vec[d] += (a[a.size()-i-1]-'0') * (b[b.size()-j-1]-'0');
                }
            }
        }
        for (int i = 0; i < vec.size()-1; i++) {
            if (vec[i] >= 10) {
                vec[i+1] += vec[i]/10;
                while(vec[i] >= 10) vec[i] %= 10;
            }
        }
        while (vec[vec.size()-1] >= 10) {
            vec.push_back(vec[vec.size()-1]/10);
            while(vec[vec.size()-2] >= 10) vec[vec.size()-2] %= 10;
        }
    }
    else {
        if (a.size() < b.size()) {
            cout << "0" << endl;
            return 0;
        }
        else if (a.size() == b.size()) {
            if ((b[0]-'0') > (a[0]-'0')) {
                cout << "0" << endl;
                return 0;
            }
            else if ((a[0]-'0') == (b[0]-'0')) {
                for (int i = 1; i < a.size(); i++) {
                    if ((b[i]-'0') > (a[i]-'0')) {
                        cout << "0" << endl;
                        return 0;
                    }
                }
                cout << "1" << endl;
                return 0;
            }
            else cout << (a[0]-'0') / (b[0]-'0') << endl;
        }
        else { // 未完成
        }
    }
    for (int i = vec.size()-1; i >= 0; i--) {
        if (vec[i] == '-') cout << "-";
        else cout << vec[i];
    }
    cout << endl;
    return 0;
}

