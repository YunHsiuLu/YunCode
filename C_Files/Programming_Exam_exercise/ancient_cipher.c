#include <stdio.h>
#include <stdlib.h>

void pat_check(int *arr, char *chh, char *str, size_t len);

int main() {
	char *cipher, *plain;
	cipher = (char *)malloc(sizeof(char)*100);
	plain = (char *)malloc(sizeof(char)*100);
	printf("Please input the cipher: ");
	scanf("%s", cipher);
	printf("Please input the plain text: ");
	scanf("%s", plain);

	size_t cipher_size = 0;
	size_t plain_size = 0;
	while (cipher[cipher_size] != 0) cipher_size++;
	while (plain[plain_size] != 0) plain_size++;
	if (cipher_size != plain_size) printf("NO!\n");
	else {
		//pattern check
		int *c_arr, *p_arr;
		char *c_chh, *p_chh;
		c_arr = (int *)malloc(sizeof(char)*cipher_size);
		c_chh = (char *)malloc(sizeof(char)*cipher_size);
		p_arr = (int *)malloc(sizeof(char)*plain_size);
		c_chh = (char *)malloc(sizeof(char)*plain_size);
		printf("cipher pattern check\n");
		pat_check(c_arr, c_chh, cipher, cipher_size);
		printf("plain pattern check\n");
		pat_check(p_arr, p_chh, plain, plain_size);

		free(c_arr);
		free(c_chh);
		free(p_arr);
		free(p_chh);
	}
	free(cipher);
	free(plain);
	return 0;

}

void pat_check(int *arr, char *chh, char *str, size_t len) {
	int j = 0, temp = 0, exist = 0;
	for (int i = 0; i < len; i++) {
		printf("%d\n", i);
		temp = 1;
		if (!i) {
			chh[j] = str[i];
			for (int t = i+1; t < len; t++) {
				if (chh[j] == str[t]) temp++;
			}
			arr[j] = temp;
			j++;
		}
		else {
			exist = 0;
			for (int a = 0; a < j; a++) {
				if (str[i] == chh[a]) {
					exist = 1;
					break;
				}
			}
			if (exist) continue;
			chh[j] = str[i];
			for (int t = i+1; t < len; t++) {
				if (chh[j] == str[t]) temp++;
			}
			arr[j] = temp;
			j++;
		}
	}
}
