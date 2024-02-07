#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> v, int cost) {
    if (v.size()==2) return abs(v[0]-v[1]);
    vector<int> tmp;
    tmp = v;
    vector<int>::iterator tt;
    int c = 99999;
    for (int i = 0; i < tmp.size()-1; i++) {
        tt = tmp.begin() + i;
        int p1 = tmp[i], p2 = tmp[i+1];
        tt = tmp.erase(tt, tt+2);
        tmp.insert(tt, p1+p2);
        tt = tmp.begin();
        c = min(c, abs(p1-p2) + dfs(tmp, abs(p1-p2))); 
        tmp = v;
    }
    return c;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    cin >> n;
    vector<int> vec(n);
    vector<int>::iterator it;
    for (int i = 0; i < n; i++) cin >> vec[i];
    cout << dfs(vec, 0) << endl;

    return 0;
}

