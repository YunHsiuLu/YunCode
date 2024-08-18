#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector < vector <pair <char, int> > > plus_oper(N+2);
    vector < vector <pair <char, int> > > times_oper(N+2);

    while (M--) {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        if (r == 1) {
            plus_oper[p].emplace_back('+', s);
            plus_oper[q+1].emplace_back('-', s);
        }
        else {
            times_oper[p].emplace_back('*', s);
            times_oper[q+1].emplace_back('/', s);
        }
    }

    long long Max_coin = 0, rc = 0, cc = 0, rm = 1;
    int Max_coin_pos = INT_MAX;
    for (int i = 1; i <= N+1; i++) {
        for (int j = 0; j < plus_oper[i].size(); j++) {
            if (plus_oper[i][j].first == '+') rc += plus_oper[i][j].second;
            else if (plus_oper[i][j].first == '-') rc -= plus_oper[i][j].second;
        }
        for (int j = 0; j < times_oper[i].size(); j++) {
            if (times_oper[i][j].first == '*') rm *= times_oper[i][j].second;
            else if (times_oper[i][j].first == '/') rm /= times_oper[i][j].second;
        }
        cc = rc*rm;
        if (Max_coin < cc) {
            Max_coin = cc;
            Max_coin_pos = i;
        }
    }

    printf("%d %lld\n", Max_coin_pos, Max_coin);
    return 0;
}

