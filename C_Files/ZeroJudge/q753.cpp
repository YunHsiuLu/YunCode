#include <iostream>
using namespace std;

int main() {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int D = a1*b2 - a2*b1;
    int Dx = c1*b2 - c2*b1;
    int Dy = a1*c2 - a2*c1;
    if (D != 0) {
        float x = (float)Dx/D;
        float y = (float)Dy/D;
        printf("%.3f %.3f\n", x, y);
    }
    else if ((!D) && (!Dx) && (!Dy)) cout << "INF" << endl;
    else cout << "NONE" << endl;
	return 0;
}

