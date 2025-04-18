#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char num[11];
	int length, i, j, k, first, second, flag = 0;

	scanf("%s", num, sizeof(num));
	length = strlen(num);

	for (i = 0; i < length - 1; i++) {
		first = 1; second = 1;
		for (j = 0; j <= i; j++) {
			first *= (num[j] - '0');
		}
		for (k = i + 1; k < length; k++) {
			second *= (num[k] - '0');
		}
		if (first == second) {
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		printf("YES\n");
	else
		printf("NO\n");
}