#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, Max = -99, min = 1000;
    cin >> n;
    int Score[n];
    for (int i = 0; i < n; i++) {
        cin >> Score[i];
        if (Score[i] > Max && Score[i] < 60) Max = Score[i];
        if (Score[i] < min && Score[i] >= 60) min = Score[i];
    }
    
    sort(Score, Score+n);
    
    for (int i = 0; i < n-1; i++) cout << Score[i] << " ";
    cout << Score[n-1] << endl;
    if (Max < 0) cout << "best case" << endl;
    else cout << Max << endl;
    
    if (min > 100) cout << "worst case" << endl;
    else cout << min << endl;

    return 0;
}
