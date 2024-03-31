#include <iostream>
#include <climits>
#include <algorithm>
#include <tuple>
using namespace std;

long long N, M, a[100000], b[100000], r, c, d;
tuple<long long, long long, long long> x[100000];   // <與最近捷運站距離, 月租, 編號>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i] >> b[i] >> r;
        x[i] = make_tuple(LLONG_MAX, r, i+1);
    }
    
    for(int i = 0; i < M; ++i)
    {
        cin >> c >> d;
        for(int j = 0; j < N; ++j)
            get<0>(x[j]) = min(get<0>(x[j]), (a[j]-c)*(a[j]-c) + (b[j]-d)*(b[j]-d));
    }
    
    sort(x, x + N);
    for(int i = 0; i < N; ++i)  cout << get<2>(x[i]) << "\n";
}
NODE[j].dis = tmp;
            }
        }
    }
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            if (NODE[i].dis > NODE[j].dis) {
                node tmp = NODE[j];
                NODE[j] = NODE[i];
                NODE[i] = tmp;
            }
        }
    }
    for (int i = 1; i <= n-1; i++) {
        if (NODE[i].dis == NODE[i+1].dis) {
            if ((NODE[i].price > NODE[i+1].price) || ((NODE[i].price == NODE[i+1].price) && (NODE[i].number > NODE[i+1].number))) {
                node tmp = NODE[i+1];
                NODE[i+1] = NODE[i];
                NODE[i] = tmp;
            }
        }
        cout << NODE[i].number << endl;
    }
    cout << NODE[n].number << endl;
	return 0;
}

