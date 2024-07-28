#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Node {
    char c = ' ';
    int Parent = 0, L = 0, R = 0;
    bool check = 0;
};

int main() {
    string s;
    cin >> s;
    int n = s.size()+1;
    Node Tree[n]; // Tree[0] for null; Tree[1] ~ Tree[s.size()] for nodes
    int i = 1;
    // build the tree
    while (i < n) {
        if (s[i-1] == '-') {
            i++;
            continue;
        }
        Tree[i].c = s[i-1];
        if (i > 1) {
            Tree[i].Parent = i/2;
            if (i%2 == 0) Tree[i/2].L = i;
            else Tree[i/2].R = i;
        }
        i++;
    }
    // print the tree
    /*
    for (i = 1; i < n; i++) {
        if (Tree[i].c == ' ') continue;
        printf("node: %c\tParent: %c\tLeft: %c\tRight: %c\n", Tree[i].c, Tree[Tree[i].Parent].c, Tree[Tree[i].L].c, Tree[Tree[i].R].c);
    }
    */
    // count the distance
    int q;
    cin >> q;
    while (q--) {
        char start, end;
        int START, END;
        int count = 0;
        deque<int> qu1, qu2;
        cin >> start >> end;
        for (int t = 1; t < n; t++) {
            Tree[t].check = 0;
            if (Tree[t].c == start) START = t;
            if (Tree[t].c == end) END = t;
        }
        //printf("START: %d END: %d\n", START, END);
        // BFS
        qu1.push_back(START);
        while(!qu1.empty() || !qu2.empty()) {
            /*
            cout << "qu1: ";
            for (int a = 0; a < qu1.size(); a++) cout << qu1[a] << " ";
            cout << endl;
            cout << "qu2: ";
            for (int a = 0; a < qu2.size(); a++) cout << qu2[a] << " ";
            cout << endl;
            */
            int TEMP = qu1.front();
            qu1.pop_front();
            Tree[TEMP].check = 1;
            if (Tree[TEMP].c == Tree[END].c) {
                cout << count << endl;
                break;
            }
            if (Tree[TEMP].Parent && !Tree[Tree[TEMP].Parent].check) qu2.push_back(Tree[TEMP].Parent);
            if (Tree[TEMP].L && !Tree[Tree[TEMP].L].check) qu2.push_back(Tree[TEMP].L);
            if (Tree[TEMP].R && !Tree[Tree[TEMP].R].check) qu2.push_back(Tree[TEMP].R);
            if (qu1.empty()) {
                while (!qu2.empty()) {
                    qu1.push_back(qu2.front());
                    qu2.pop_front();
                }
                count++;
            }
        }
        //cout << "Can't find the point!" << endl;
    }
    return 0;
}

