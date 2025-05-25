#include <stdio.h>

int main()
{
	const int size = 20;
	char name[size] = { "Edgar" };
	FILE* out;
	out = fopen("test.c", "w");
	if (!out)
	{
		perror("fopen");
		return 1;
	}
	fwrite(name, sizeof(char), 3, out);
	fclose(out);

	FILE* in;
	in = fopen("test.c", "r");
	if (!in)
	{
		perror("fopen");
		return 1;
	}
	printf("%s", fgets(name, size, in));
	fclose(in);
}
