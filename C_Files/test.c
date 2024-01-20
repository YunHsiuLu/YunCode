#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char ch[] = "English";
	char ch2[] = "Spain";
	char ch_0[10];
	char ch2_0[10];
	sprintf(ch_0, "%c", &ch);
	sprintf(ch2_0, "%c", &ch2);
	int num = strcmp(ch_0, ch2_0);
	printf("%d\n", num);
	return 0;
}
