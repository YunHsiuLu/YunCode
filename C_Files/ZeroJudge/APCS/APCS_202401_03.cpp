#include <iostream>
#include <queue>
#define MAXN 55000
using namespace std;

struct node {
	int c;
	int IN1, IN2;
	int inDEG;
	int OUT;
	int outL;
};

node NODE[MAXN];
deque<int> G[MAXN];
deque<int> qu;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int p,q,r,m,x,y,ans;
	cin >> p >> q >> r >> m;
	ans = 0;
	qu.clear();
	for (int i = 0; i < MAXN; i++) G[i].clear();
	for (int i = 1; i <= p; i++) {
		cin >> NODE[i].OUT;
		NODE[i].c = -1;
		NODE[i].outL = 0;
		qu.push_back(i);
	}
	for (int i = 1+p; i <= p+q; i++) {
		cin >> NODE[i].c;
		NODE[i].outL = 0;
		NODE[i].inDEG = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		NODE[y].inDEG++;
	}
	while(!qu.empty()) {
		int f = qu.front();
		qu.pop_front();
		for (int i = 0; i < G[f].size(); i++) {
			int n = G[f][i];
			if (NODE[n].c == 1 || NODE[n].c == 2 || NODE[n].c == 3) {
				if (NODE[n].inDEG == 2) {
					NODE[n].IN1 = NODE[f].OUT;
					NODE[n].outL = max(NODE[n].outL, NODE[f].outL + 1);
					NODE[n].inDEG--;
				}
				else {
					NODE[n].IN2 = NODE[f].OUT;
					NODE[n].outL = max(NODE[n].outL, NODE[f].outL + 1);
					NODE[n].inDEG--;
					if (NODE[n].c == 1) NODE[n].OUT = NODE[n].IN1 & NODE[n].IN2;
					if (NODE[n].c == 2) NODE[n].OUT = NODE[n].IN1 | NODE[n].IN2;
					if (NODE[n].c == 3) NODE[n].OUT = NODE[n].IN1 ^ NODE[n].IN2;
					qu.push_back(n);
				}
			}
			if (NODE[n].c == 4) {
				if (NODE[n].inDEG == 1) {
					NODE[n].IN1 = NODE[f].OUT;
					NODE[n].outL = max(NODE[n].outL, NODE[f].outL + 1);
					NODE[n].inDEG--;
					NODE[n].OUT = !NODE[n].IN1;
					qu.push_back(n);
				}
			}
			if (NODE[n].c == 0) {
				NODE[n].OUT = NODE[f].OUT;
				NODE[n].outL = NODE[f].outL;
				NODE[n].inDEG--;
			}
		}
	}
	for (int i = p+q+1; i <= p+q+r; i++) ans = max(ans, NODE[i].outL);
	cout << ans << endl;
	for (int i = p+q+1; i <= p+q+r; i++) cout << NODE[i].OUT << " ";
	cout << endl;

	return 0;
}

