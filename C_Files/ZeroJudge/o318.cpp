#include <iostream>
#include <string>
using namespace std;
int main() {
    int N, Y;
    cin >> N >> Y;
    string ans_name;
    int ans_score=0;
    for (int n = 0; n < N; n++) {
        string name;
        cin >> name;
        int score = 0;
        for (int y = 0; y < Y; y++) {
            string temp;
            cin >> temp;
            if (temp == "AC") score += 100;
            else score += stoi(temp);
        }
        if (ans_score < score) {
            ans_score = score;
            ans_name = name;
        }
    }
    cout << ans_name << endl;
    return 0;
}

