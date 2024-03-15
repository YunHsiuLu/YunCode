#include <iostream>
#include <vector>
using namespace std;
void post2in(vector<int> v, int parent_root) {
    if (v.size() != 0) {
        int root = v.back();
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] < root) left.push_back(v[i]);
            else right.push_back(v[i]);
        }
        post2in(left, root);
        cout << root << " " << parent_root << endl;
        post2in(right, root);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    while (n--) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    post2in(vec, -1);

	return 0;
}

