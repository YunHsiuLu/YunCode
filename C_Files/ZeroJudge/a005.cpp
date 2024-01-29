#include <iostream>
using namespace std;
int main() {
	int line = 0;
	cin >> line;
	int a=0, b=0, c=0, d=0;
	while (!cin.eof() && (cin >> a >> b >> c >> d)) {
		if (b-a == c-b) {
			printf("%d %d %d %d %d\n", a, b, c, d, d+b-a);
		}
		else {
			printf("%d %d %d %d %d\n", a, b, c, d, d*b/a);
		}
	}
	return 0;
}

