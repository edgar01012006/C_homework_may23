#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* ptr;
	char* buf;
	int filesize;
	
	ptr = fopen("test.c", "r");
	if (!ptr)
	{
		printf("failed to open");
		return 1;
	}
	fseek(ptr, 0, SEEK_END);
	filesize = ftell(ptr);
	rewind(ptr);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, 1, filesize, ptr);
	for (int i = 0; i < filesize; ++i)
	{
			if (buf[i] >= 'a' && buf[i] <= 'z')
			{
				buf[i] -= 32;
			}
			else if(buf[i] >= 'A' && buf[i] <= 'Z')
			{
				buf[i] += 32;
			}
	}
	buf[filesize] = '\0';
	fclose(ptr);
	ptr = fopen("test.c", "w");
	if (!ptr)
	{
		printf("failed to open");
		return 1;
	}
	fwrite(buf, sizeof(char), filesize, ptr); 
	fclose(ptr);
	free(buf);
	return 0;
}
