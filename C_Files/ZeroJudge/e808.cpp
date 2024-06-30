#include <iostream>
using namespace std;

int main() {
    int STOPS, temp;
    cin >> STOPS;
    int time_slot[STOPS+1][2];
    cin >> time_slot[0][0] >> time_slot[0][1];
    for (int i = 1; i <= STOPS; i++) {
        cin >> temp;
        time_slot[i][1] = time_slot[i-1][1] + temp;
        time_slot[i][0] = time_slot[i-1][0];
        if (time_slot[i][1] >= 60) {
            time_slot[i][0] = time_slot[i-1][0] + time_slot[i][1]/60;
            time_slot[i][1] %= 60;
        }
        if (time_slot[i][0] >= 24) {
            time_slot[i][0] %= 24;
        }
    }
    while ((cin >> temp) && (temp != 0)) {
        printf("%02d:%02d\n", time_slot[temp][0], time_slot[temp][1]);
    }
    return 0;
}

