#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, Below60=0, NearBelow60=0, NearAbove60=100;
    cin >> n;
    int Score[n];
    for (int i = 0; i < n; i++) {
        cin >> Score[i];
        if (Score[i] < 60) Below60++;
    }
    sort(Score, Score+n);
    for (int i = 0; i < n; i++) {
        cout << Score[i] << " ";
        if ((Score[i] >= NearBelow60) && (Score[i] < 60)) NearBelow60 = Score[i];
        if ((Score[i] <= NearAbove60) && (Score[i] >= 60)) NearAbove60 = Score[i];
    }
    cout << endl;
    if (Below60 == n) cout << NearBelow60 << endl << "worst case";
    else if (Below60 == 0) cout << "best case" << endl << NearAbove60;
    else cout << NearBelow60 << endl << NearAbove60;
    cout << endl;
}
