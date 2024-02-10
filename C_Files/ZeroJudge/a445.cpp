#include <iostream>
#include <vector>
using namespace std;

struct node {
    vector<int> relation;
    int val;
    bool visited;
};

const int SIZE = 10000;
node PERSON[SIZE+1];
bool ans;

void dfs(node &tmp1, node &tmp2) {
    //cout << tmp1.val << " " << tmp2.val << endl;
    tmp1.visited = true;
    if (tmp1.val == tmp2.val) ans = true;
    for (int i = 0; i < tmp1.relation.size(); i++) {
        if (!PERSON[tmp1.relation[i]].visited)
            dfs(PERSON[tmp1.relation[i]], tmp2);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int first, second;
        cin >> first >> second;
        cout << first << " " << second;
        if (!PERSON[first].val) PERSON[first].val = first;
        if (!PERSON[second].val) PERSON[second].val = second;
        PERSON[first].relation.push_back(second);
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

