#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> numbers;
    for (int i = 0; i < 3; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.rbegin(), numbers.rend());
    int count = 1;
    vector<int> vec;
    vec.push_back(numbers[0]);
    if (numbers[0] == numbers[1]) count++;
    else vec.push_back(numbers[1]);

    if (numbers[1] == numbers[2]) count++;
    else vec.push_back(numbers[2]);

    cout << count << " ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    return 0;
}

