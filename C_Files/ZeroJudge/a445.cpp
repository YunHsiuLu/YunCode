#include <iostream>
using namespace std;

const int SIZE=10001;
int parent[SIZE], rk[SIZE];

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return find_parent(parent[x]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int M, N, Q;
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) rk[i] = 1;
	
	int c = 0;
	while (c < M) {
		int first, second;
		cin >> first >> second;
		if (!parent[first]) parent[first] = first;
		if (!parent[second]) parent[second] = second;
		if (rk[find_parent(first)] >= rk[find_parent(second)]) {
			parent[second] = first;
			rk[first] += rk[second];
		}
		else {
			parent[first] = second;
			rk[second] += rk[first];
		}
		c++;
	}
	c = 0;
	while (c < Q) {
		int first, second;
		cin >> first >> second;
		if (find_parent(first) == find_parent(second)) cout << ":)" << endl;
		else cout << ":(" << endl;
		c++;
	}
	return 0;
}

<< endl;
		c++;
	}
	return 0;
}

PERSON[second].relation.push_back(first);
    }
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < N; j++) PERSON[j].visited = false;
        ans = false;
        int first, second;
        cin >> first >> second;
        dfs(PERSON[first], PERSON[second]);
        if (ans) cout << ":)\n";
        else cout << ":(\n";
    }

	return 0;
}

