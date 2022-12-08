#include <stdio.h>
#include <stdlib.h>

int insert_sort(int p, int *arr, size_t size);
int pat_check(int *arr, char *chh, char *str, size_t len);
int debug = 0;

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
		c_arr = (int *)malloc(sizeof(int)*cipher_size);
		c_chh = (char *)malloc(sizeof(char)*cipher_size);
		p_arr = (int *)malloc(sizeof(int)*plain_size);
		p_chh = (char *)malloc(sizeof(char)*plain_size);

		int c_nofchr = 0, p_nofchr = 0;
	
		c_nofchr = pat_check(c_arr, c_chh, cipher, cipher_size);
		p_nofchr = pat_check(p_arr, p_chh, plain, plain_size);
		if (debug) {
			printf("\ncipher pattern check\n");
			printf("c_arr:\n");
			for(int i = 0; i < c_nofchr; i++) printf("%c, ", c_chh[i]);
			printf("\n");
			for(int i = 0; i < c_nofchr; i++) printf("%d, ", c_arr[i]);
			printf("\n");
			printf("\nplain pattern check\n");
			printf("p_arr:\n");
			for(int i = 0; i < p_nofchr; i++) printf("%c, ", p_chh[i]);
			printf("\n");
			for(int i = 0; i < p_nofchr; i++) printf("%d, ", p_arr[i]);
			printf("\n");
			printf("No. of c & p: %d %d\n\n", c_nofchr, p_nofchr);
		}
		
		//decrypt
		//test the most number of character
		int All_success = 1, success = 0, swap = 0;
		for (int i = 0; c_arr[0] == p_arr[i]; i++) {
			if(debug) printf("Let %c is %c:\n", c_chh[0], p_chh[i]);
			swap = (int)c_chh[0] - p_chh[i];
			swap = (swap>=0) ? swap : swap+26;
			for (int j = 1; j < c_nofchr; j++) {
				All_success = 1;
				for (int k = 0; k < p_nofchr; k++) {
					success = 0;
					if (k == i) continue;
					if (c_arr[j] != p_arr[k]) continue;
					char tt = ((int)p_chh[k]+swap <=90) ? (char)p_chh[k]+swap : (char)((p_chh[k]+swap)%90+64);
					if (tt == c_chh[j]) success = 1;
					if (debug && success) printf("----success\n%c is %c\n", c_chh[j], p_chh[k]);
				}
				All_success = All_success && success;
			}
			if (All_success) {
				printf("YES!\n");
				break;
			}
		}
		
		free(c_arr);
		free(c_chh);
		free(p_arr);
		free(p_chh);
	}
	free(cipher);
	free(plain);
	return 0;
}

int insert_sort(int p, int *arr, size_t size) {
	int pos = -999;
	for (int i = 0; i < size; i++) {
		if (p >= arr[i]) {
			for (int j = size-1; j >= i; j--) arr[j+1] = arr[j];
			pos = i;
			break;
		}
		else {
			pos = i+1;
		}
	}
	arr[pos] = p;
	return pos;
}

int pat_check(int *arr, char *chh, char *str, size_t len) {
	int j = 0, temp = 0, exist = 0;
	int swap = 0;
	for (int i = 0; i < len; i++) {
		if (debug) printf("%d: %c\n", i, str[i]);
		temp = 1;
		if (!i) {
			chh[j] = str[i];
			for (int t = i+1; t < len; t++) {
				if (chh[j] == str[t]) temp++;
			}
			arr[j] = temp;
			if (debug) printf("\t%c: %d\n", chh[j], arr[j]);
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
			for (int t = i+1; t < len; t++) {
				if (str[i] == str[t]) temp++;
			}
			if(debug) printf("\t%c: %d\n", str[i], temp);
			swap = insert_sort(temp, arr, i);
			for (int t = i-1; t >= swap; t--) chh[t+1] = chh[t];
			chh[swap] = str[i];
			j++;
		}
		if (debug) {
			for (int tt = 0; tt < j; tt++) printf("%d, ", arr[tt]);
			printf("\n");
		}
	}
	return j;
}
