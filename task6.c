#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* ptr;
	char* buf;
	int filesize;
	
	ptr = fopen("test6.c", "r");
	if (!ptr)
	{
		printf("fopen");
		return 1;
	}
	fseek(ptr, 0, SEEK_END);
	filesize = ftell(ptr);
	rewind(ptr);
	//printf("filesize = %d", filesize);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, sizeof(char), filesize, ptr);
	buf[filesize] = '\0';
	fclose(ptr);

	printf("%s", buf);
	free(buf);
	return 0;
}
