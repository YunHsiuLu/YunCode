#include <iostream>
using namespace std;
int main() {
    int* c = new int[3];
    for (int i = 0; i < 3; i++)
        c[i] = i+1;
    cout << *c << endl;
    cout << *(c+1) << endl;
    cout << *(c+2) << endl;

    c = new int[5];
    for (int i = 0; i < 5; i++)
        c[i] = i*2 + 1;
    cout << *c << endl;
    cout << *(c+1) << endl;
    cout << *(c+2) << endl;
    cout << *(c+3) << endl;
    cout << *(c+4) << endl;
    return 0;
}
