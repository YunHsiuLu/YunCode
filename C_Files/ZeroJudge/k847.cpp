#include <iostream>
using namespace std;

int main() {
	int month[2], day[2];
	cin >> month[0] >> day[0];
	cin >> month[1] >> day[1];
	int tmp=0;
	while ((month[0] != month[1]) || (day[0] != day[1])) {
		if (((month[0] == 1) || (month[0] == 3) || (month[0] == 5) || (month[0] == 7) || (month[0] == 8) || (month[0] == 10) || (month[0] == 12)) && (day[0] == 31) ){
			month[0]++;
			day[0] = 1;
		}
		else if (((month[0] == 4) || (month[0] == 6) || (month[0] == 9) || (month[0] == 11)) && (day[0] == 30)) {
			month[0]++;
			day[0] = 1;
		}
		else if ((month[0] == 2) && (day[0] == 28)) {
			month[0]++;
			day[0] = 1;
		}
		else {
			day[0]++;
		}
		tmp++;
		//cout << month[0] << " " << day[0] << endl;
	}
	tmp++;
	tmp = tmp/10*9 + tmp%10;
	cout << tmp*100 << endl;
	return 0;
}

