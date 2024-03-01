#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    float h, w, bmi;
    while (n--) {
        cin >> h >> w;
        bmi = w/(h*h);
        if (bmi < 18.5) cout << "過輕" << endl;
        else if ((bmi >= 18.5) && (bmi < 24)) cout << "正常" << endl;
        else if ((bmi >= 24) && (bmi < 35)) cout << "異常" << endl;
        else cout << "要小心了!" << endl;
    }
	return 0;
}

