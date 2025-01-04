#include <iostream>
#include <vector>
using namespace std;

// 全域變數
unsigned long long ans = 0;

// 定義 ROOM 節點結構
struct ROOM {
    int val;
    ROOM *Left;
    ROOM *Right;
    ROOM *Center;
    ROOM *Top;

    ROOM() : val(-1), Left(nullptr), Right(nullptr), Center(nullptr), Top(nullptr) {}
};

// 遞迴構建樹與計算
void Travel(ROOM *r, vector<int> &inputs, int &index) {
    if (index >= inputs.size()) return; // 若輸入已讀完，直接返回
    int a = inputs[index++];           // 讀取當前數字
    if (a == 0) return;                // 遇到 0 時結束當前遞迴

    r->val = a; // 設置當前節點的值

    // 如果當前節點有父節點，累加差值到 ans
    if (r->Top != nullptr) {
        //printf("r->val: %d, r->Top->val: %d\n", r->val, r->Top->val);
        ans += abs((r->val) - (r->Top->val));
    }

    // 建立左右子節點並遞迴處理
    r->Left = new ROOM();
    r->Right = new ROOM();
    r->Left->Top = r;
    r->Right->Top = r;

    Travel(r->Left, inputs, index); // 遍歷左節點

    // 如果是奇數，建立中間子節點並遞迴處理
    if (a % 2 == 1) {
        r->Center = new ROOM();
        r->Center->Top = r;
        Travel(r->Center, inputs, index);
    }

    Travel(r->Right, inputs, index); // 遍歷右節點
}

int main() {
    // 讀取輸入（單行數字）
    vector<int> inputs;
    int num;
    while (cin >> num) {
        inputs.push_back(num);
    }

    // 檢查輸入是否為空
    if (inputs.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // 建立根節點
    ROOM *root = new ROOM();

    // 開始構建樹並計算
    int index = 0;
    Travel(root, inputs, index);

    // 輸出結果
    cout << ans << endl;

    return 0;
}
