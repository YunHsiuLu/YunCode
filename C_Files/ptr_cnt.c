#include <stdio.h>

#define set_cnt(ptr, cnt) (ptr = (int*)(long)(cnt))
#define	get_cnt(ptr) ((int)(long)(ptr))

int main() {
	int *ptr;
	int a = 2, b = 3, c;
	set_cnt(ptr, a+b);
	c = get_cnt(ptr);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
}
