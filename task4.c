#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* buf;
	FILE* ptr;
	int filesize;
	int readsize = 0;
	
	ptr = fopen("test4.c", "r");
	if (!ptr)
	{
		printf("failed to open");
		return 1;
	}
	fseek(ptr, 0, SEEK_END);
	filesize = ftell(ptr);
	rewind(ptr);
	
	do
	{
		scanf("%d", &readsize);
	}while(readsize > filesize);

	buf = (char*) malloc(sizeof(char) * (readsize + 1));
	fread(buf, sizeof(char), readsize, ptr);
	fseek(ptr, readsize, SEEK_END);
	fread(buf, sizeof(char), readsize, ptr);
	buf[readsize] = '\0';
	printf("%s", buf);
	fclose(ptr);
	free(buf);
	return 0;
}
