#include <iostream>
using namespace std;

struct MAP {
    char c;
    int check = 0;
};

MAP map[505][505];
int n, m;
int ans_max = 0, temp = 0;

void bfs(int x, int y) {
    map[y][x].check = 1;
    temp++;
    if ((map[y][x].c == 'I' || map[y][x].c == 'X' || map[y][x].c == 'L' || map[y][x].c == 'J')
        && y-1 >= 0
        && (map[y-1][x].c == 'I' || map[y-1][x].c == 'X' || map[y-1][x].c == '7' || map[y-1][x].c == 'F')
        && !map[y-1][x].check) bfs(x, y-1);
    if ((map[y][x].c == 'I' || map[y][x].c == 'X' || map[y][x].c == '7' || map[y][x].c == 'F') 
        && y+1 < n
        && (map[y+1][x].c == 'I' || map[y+1][x].c == 'X' || map[y+1][x].c == 'L' || map[y+1][x].c == 'J')
        && !map[y+1][x].check) bfs(x, y+1);
    if ((map[y][x].c == 'H' || map[y][x].c == 'X' || map[y][x].c == '7' || map[y][x].c == 'J')
        && x-1 >= 0
        && (map[y][x-1].c == 'H' || map[y][x-1].c == 'X' || map[y][x-1].c == 'L' || map[y][x-1].c == 'F')
        && !map[y][x-1].check) bfs(x-1, y);
    if ((map[y][x].c == 'H' || map[y][x].c == 'X' || map[y][x].c == 'L' || map[y][x].c == 'F')
        && x+1 < m
        && (map[y][x+1].c == 'H' || map[y][x+1].c == 'X' || map[y][x+1].c == '7' || map[y][x+1].c == 'J')
        && !map[y][x+1].check) bfs(x+1, y);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j].c;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp = 0;
            if (map[i][j].c == '0') continue;
            bfs(j, i);
            ans_max = max(ans_max, temp);
        }
    }

    cout << ans_max << endl;
    
    return 0;
}

