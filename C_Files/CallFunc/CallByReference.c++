#include <stdio.h>

void foo(int &x);

int main() {
    int x = 5;
    foo(x);
    printf("%d\n", x);
}

void foo(int &x) {
    x++;
}
