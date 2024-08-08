#include <iostream>
using namespace std;

struct BUS {
    int value;
    int time;
    int station[5];
};

int main() {
    int n;
    cin >> n;
    BUS bus[5];
    bus[0].value = 734;
    bus[0].time = 5;
    bus[0].station[0] = 0;
    bus[0].station[1] = 4;
    bus[0].station[2] = 8;
    bus[0].station[3] = 6;
    bus[0].station[4] = 12;

    bus[1].value = 632;
    bus[1].time = 8;
    bus[1].station[0] = 4;
    bus[1].station[1] = 1;
    bus[1].station[2] = 9;
    bus[1].station[3] = 6;
    bus[1].station[4] = 8;
    
    bus[2].value = 8;
    bus[2].time = 17;
    bus[2].station[0] = 11;
    bus[2].station[1] = 2;
    bus[2].station[2] = 3;
    bus[2].station[3] = 5;
    bus[2].station[4] = 9;
    
    bus[3].value = 612;
    bus[3].time = 20;
    bus[3].station[0] = 5;
    bus[3].station[1] = 4;
    bus[3].station[2] = 6;
    bus[3].station[3] = 7;
    bus[3].station[4] = 4;
    
    bus[4].value = 302;
    bus[4].time = 45;
    bus[4].station[0] = 4;
    bus[4].station[1] = 11;
    bus[4].station[2] = 88;
    bus[4].station[3] = 8;
    bus[4].station[4] = 0;

    while (n--) {
        int start, end, b=0;
        cin >> start >> end;
        for (int i = 0; i < 5; i++) {
            int c_s=0, c_e=0;
            for (int j = 0; j < 5; j++) {
                if (bus[i].station[j] == start) c_s = 1;
                if (bus[i].station[j] == end) c_e = 1;
            }
            if (c_s && c_e) {
                cout << bus[i].value << endl;
                b = 1;
                break;
            }
        }
        if (!b) cout << "別騙我喔,qwq" << endl;
    }
    
    return 0;
}

