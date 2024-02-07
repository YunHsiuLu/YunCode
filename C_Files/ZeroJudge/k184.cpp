#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int number = 0;
    int x = 0;
    int y = 0;
    int price = 0;
    double dis = 0.;
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    node NODE[n+m+1];
    for (int i = 1; i <= n; i++) {
        NODE[i].number = i;
        cin >> NODE[i].x >> NODE[i].y >> NODE[i].price;
    }
    for (int i = n+1; i <= m+n; i++) {
        NODE[i].number = i-n;
        cin >> NODE[i].x >> NODE[i].y;
        for (int j = 1; j <= n; j++) {
            double tmp = sqrt(pow(NODE[i].x-NODE[j].x, 2) + pow(NODE[i].y-NODE[j].y, 2));
            if (i == n+1) NODE[j].dis = tmp;
            else {
                if (tmp < NODE[j].dis) NODE[j].dis = tmp;
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

