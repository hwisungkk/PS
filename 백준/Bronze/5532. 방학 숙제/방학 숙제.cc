#include <stdio.h>

int main()
{
	int L, A, B, C, D, num1 = 0, num2 = 0;
	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);

	num1 = A / C;
	if (A % C != 0)
	{
		num1++;
	}
	num2 = B / D;
	if (B % D != 0)
	{
		num2++;
	}
	if (num1 >= num2)
	{
		printf("%d", L - num1);
	}
	else
	{
		printf("%d", L - num2);
	}
	return 0;
}