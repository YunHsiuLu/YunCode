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
