#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* ptr;
	int filesize;
	char* buf;

	ptr = fopen("test7.c", "r");
	if(!ptr)
	{
		printf("fopen");
		return 1;
	}
	fseek(ptr, 0, SEEK_END);
	filesize = ftell(ptr);
	rewind(ptr);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, sizeof(char), filesize, ptr);
	buf[filesize] = '\0';
	fclose(ptr);

	int cnt_lines = 0;
	int cnt_words = 0;
	int flag = 0;

	for (int i = 0; i < filesize; ++i)
	{
		if(buf[i] == '\n')
		{
			++cnt_lines;
			++cnt_words;
			flag = 1; 
		}
		if (buf[i] == ' ' && flag == 0)
		{
			++cnt_words;
			flag = 0;
		}
	}

	printf("cnt_lines = %d, cnt_words = %d, cnt_bytes = %d", cnt_lines, cnt_words, filesize);
	free(buf);
	return 0;
}
