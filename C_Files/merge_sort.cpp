#include <iostream>
using namespace std;

void MERGE(int *a) {
	int n = sizeof(a)/2;
	cout << n << endl;
	int *la, *ra;
	if (n != 1) {
		int ln = n/2;
		int rn = (n%2==0) ? n/2 : n/2+1;
		cout << ln << " " << rn << endl;
		la = new int [ln];
		for (int i = 0; i < ln; i++) la[i] = a[i];
		ra = new int [rn];
		for (int i = 0; i < rn; i++) ra[i] = a[i+ln];
		MERGE(la);
		MERGE(ra);
	}
	int tmp[n];
	int i = 0, j = 0;
	while (true) {
		cout << i << " " << j << endl;
		if (i == sizeof(la)/2) {
			for (int k = j; k < sizeof(ra)/2; k++) tmp[k+i] = ra[k];
			break;
		}
		else if (j == sizeof(ra)/2) {
			for (int k = i; k < sizeof(la)/2; k++) tmp[k+j] = la[k];
			break;
		}
		else {}

		if(ra[j] < la[i]) {
			tmp[i+j] = ra[j];
			j++;
		}
		else {
			tmp[i+j] = la[i];
			i++;
		}
	}
	a = tmp;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int *a = new int [n];
	for (int i = 0; i < n; i++) cin >> a[i];
	MERGE(a);
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}

