#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, score=INT_MIN, wrong = 0, time = INT_MAX;
    cin >> n;
    int t, s;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        if (s == -1) wrong++;
        else if (score < s) {
            score = s;
            time = t;
        }
    }
    score = max(score - n - 2*wrong, 0);
    printf("%d %d\n", score, time);
    
    return 0;
}

