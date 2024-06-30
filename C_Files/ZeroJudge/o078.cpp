#include <iostream>
#include <cmath>
#include <map>
#include <string>
using namespace std;

int n;
string s;
map<string, int> MAP;

void DFS(string add) {
	if (add.size() == n) {
		MAP[add] = 1;
		return;
	}
	for (int i = 0; i < s.size(); i++) DFS(add+s[i]);
}

int main() {
	string check;
	cin >> s >> n >> check;
	DFS("");
	
	map<string, int> appear;
	for (int i = 0; i <= check.size()-n; i++) {
		string temp="";
		for (int j = i; j < i+n; j++) temp += check[j];
		appear[temp]++;
	}
	for (auto i: MAP) {
		if (appear[i.first] == 0) {
			cout << i.first << endl;
			break;
		}
	}
	return 0;
}

