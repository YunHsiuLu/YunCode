#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *ptr;
	ptr = fopen("test.txt", "r");

	char lines[5];
	fgets(lines, 5, ptr);
	for (int i = 0; i < 5; i++) printf("%c ", lines[i]);
	printf("%s\n", lines);

	fclose(ptr);
	return 0;
}
