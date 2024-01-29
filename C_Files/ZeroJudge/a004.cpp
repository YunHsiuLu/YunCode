#include <iostream>
using namespace std;

int main() {
	int year = 0;
	while((cin >> year) && (!cin.eof())) {
		if (((year%4==0) && (year%100!=0)) || (year%400==0)) cout << "閏年" << endl;
		else cout << "平年" << endl;
	}
	return 0;
}

