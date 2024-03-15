#include <iostream>
#include <vector>
using namespace std;

int operand(vector<int> &post, vector<int> &oper) {
    int b = post.back();
    int a = post.back();
    char c = oper.back();
    post.pop_back();
    post.pop_back();
    oper.pop_back();
    if (c=='+') return a+b;
    if (c=='-') return a-b;
    if (c=='*') return a*b;
    if (c=='/') return a/b;
    if (c=='%') return a%b;
    return 0;
}

int main() {
    vector<int> post;
    vector<int> oper;
    char c;
    while ((cin >> c) && (c !='\n')) {
        if ((c=='*') || (c=='/') || (c=='%') || (c=='+') || (c=='-') || (c=='('))
            oper.push_back(c);
        else if (c==')') {
            while (oper.back() != '(') post.push_back(operand(post, oper));
            oper.pop_back();
        }
        else {
            post.push_back(c-'0');
            if ((oper.size() > 0) && ((oper.back() == '*') || (oper.back() == '/') || (oper.back() == '%'))) post.push_back(operand(post, oper));
        }
    }
    while (oper.size() > 0) post.push_back(operand(post, oper));

    cout << post[0] << endl;
	return 0;
}

