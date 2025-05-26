#include <stdio.h>
#include <stdlib.h>

int factorial_cal(int num)
{
	int res = 1;
	for (int i = 1; i <= num; ++i)
	{
		res *= i;
	}
	return res;
}

void reverse_buf(char* buf)
{
	char* ptr1 = buf;
	char* ptr2 = buf;
	while (*ptr2 != '\0')
	{
		++ptr2;
	}
	--ptr2;
	while (ptr1 < ptr2)
	{
		char swap = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = swap;
		++ptr1;
		--ptr2;
	}
}

void place_num_in_buf(char* buf, int num)
{
	int i = 0;
	int rev_num = 0;

	while (num != 0)
	{
		buf[i] = (num % 10) + '0';
		num /= 10;
		++i;
	}
	buf[i] = '\0';
}

int main()
{
	FILE* ptr;
	int num = 0;
	scanf("%d", &num);
	int i = 1;
	char buf[10];
	
	ptr = fopen("factorials.txt", "w");
	if (!ptr)
	{
		printf("fopen");
		return 1;
	}
	while (i <= num)
	{
		place_num_in_buf(buf, factorial_cal(i));
		reverse_buf(buf);
		fputs(buf, ptr);
		fputc(',', ptr);
		fputc(' ', ptr);
		++i;
	}
	fclose(ptr);
	return 0;
}
