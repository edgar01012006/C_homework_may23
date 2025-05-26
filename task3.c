#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* buf;
	FILE* ptr;
	int filesize;
	int cnt = 0;

	ptr = fopen("test3.c", "r");
	if (!ptr)
	{
		printf("failed to open");
		return 1;
	}
	fseek(ptr, 0, SEEK_END);
	filesize = ftell(ptr);
	rewind(ptr);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, sizeof(char), filesize, ptr);
	for (int i = 0; i < filesize; ++i)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			++cnt;
		}
	}
	buf[filesize] = '\0';
	fclose(ptr);
	free(buf);

	printf("cnt of numbers = %d\n", cnt);
	return 0;
}
