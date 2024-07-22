#include <iostream>
using namespace std;

void test(int *x) {
    printf("\tbefore changing x: x=%d\n", *x);
    *x = 5;
    printf("\tafter changing x:  x=%d\n", *x);
}

int main() {
    int a = 0;
    printf("before calling test(): a=%d\n", a);
    test(&a);
    printf("after calling test():  a=%d\n", a);
    return 0;
}

