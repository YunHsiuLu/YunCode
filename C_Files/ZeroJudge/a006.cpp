#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a=0, b=0, c=0;
	cin >> a >> b >> c;
	int b2 = pow(b, 2);
	if (b2-4*a*c < 0) cout << "No real root";
	else if (b2-4*a*c == 0) {
		cout << "Two same roots x=";
		cout << -b/2/a;
	}
	else {
		cout << "Two different roots x1=";
		cout << (-b+sqrt(b2-4*a*c))/2/a << " , x2=";
		cout << (-b-sqrt(b2-4*a*c))/2/a;
	}
	
	return 0;
}

