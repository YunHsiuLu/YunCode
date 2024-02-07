#include <iostream>
#include <vector>
using namespace std;

void MERGE(vector<int> &a) {
	int n = a.size();
    vector<int> la, ra;
	if (n != 1) {
		int ln = n/2;
		int rn = (n%2==0) ? n/2 : n/2+1;
		for (int i = 0; i < ln; i++) la.push_back(a[i]);
		for (int i = 0; i < rn; i++) ra.push_back(a[i+ln]);
		MERGE(la);
		MERGE(ra);
	}
    else return;

	int i = 0, j = 0;
    a.clear();
    a.resize(la.size()+ra.size());
    while (true) {
		if (i == la.size()) {
            for (int k = j; k < ra.size(); k++) a[i+k] = ra[k];
            break;
        }
        else if (j == ra.size()) {
            for (int k = i; k < la.size(); k++) a[j+k] = la[k];
            break;
        }

		if(ra[j] < la[i]) {
			a[i+j] = ra[j];
			j++;
		}
		else {
			a[i+j] = la[i];
			i++;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int> vec;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        vec.push_back(tmp);
    }
	MERGE(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
	cout << endl;

	return 0;
}

