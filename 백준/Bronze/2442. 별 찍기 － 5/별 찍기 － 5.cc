#include <stdio.h>
typedef struct score {
	double d;
	int arr[11];
} SCORE;
struct student {
	SCORE s[3];
	int no;
};
int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		for (int j = a - i; j > 1; j--) {
			printf(" ");
		}
		for (int j = 1; j <= 2*i+1; j++) {
			printf("*");
		}
		printf("\n");
	}
}