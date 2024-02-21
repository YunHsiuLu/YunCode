#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int R, n;
    cin >> R >> n;
    char arrow;
    string word;
    int x, y;
    char MAP[R][R];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < R; j++)
            MAP[i][j] = '_';
    bool b = 1;
    while (n--) {
        cin >> arrow >> word >> x >> y;
        cout << endl;
        for (int i = 0; i < word.length(); i++) {
            if ((y >= R) || (x >= R)) {
                b = 0;
                break;
            }
            if (arrow == 'V') {
                if ((MAP[y][x] != '_') && (word.at(i) != MAP[y][x])) {
                    b = 0;
                    break;
                }
                else {
                    MAP[y][x] = word.at(i);
                    y++;
                }
            }
            else {
                if ((MAP[y][x] != '_') && (word.at(i) != MAP[y][x])) {
                    b = 0;
                    break;
                }
                else {
                    MAP[y][x] = word.at(i);
                    x++;
                }
            }
            /*
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < R; j++) {
                    cout << MAP[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;*/
        }
        if (!b) {
            cout << "No" << endl;
            break;
        }
    }
    if (b) cout << "Yes" << endl;

	return 0;
}

