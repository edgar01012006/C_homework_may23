#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	FILE* ptr1;
	FILE* ptr2;
	int filesize;
	char* buf;


	ptr1 = fopen("a.txt", "r");
	if (!ptr1)
	{
		printf("failed to open");
		return 1;
	}
	fseek(ptr1, 0, SEEK_END);
	filesize = ftell(ptr1);
	rewind(ptr1);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, sizeof(char), filesize, ptr1);
	buf[filesize] = '\0';
	fclose(ptr1);

	ptr2 = fopen("b.txt", "w");
	if (!ptr2)
	{
		printf("failed to open");
		return 1;
	}
	reverse_buf(buf);
	fwrite(buf, sizeof(char), filesize, ptr2);
	fclose(ptr2);
	
	free(buf);
	return 0;
}
