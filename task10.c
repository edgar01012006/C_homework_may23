#include <stdio.h>
#include <stdlib.h>

typedef struct Word
{
	char arr[20];
	int cnt;
}Word;

int len(char* str); //without \0 count
int cmp_strings(char* W_str, char* buf, const int length);
int seek_word(Word* ptr, int Word_size, char* buf); //Word_size the amount of words currently placed in Word array

int main()
{
	FILE* ptr1;
	FILE* ptr2;
	int filesize;
	char* buf;
	
	ptr1 = fopen("Text.txt", "r");
	if (!ptr1)
	{
		printf("fopen1");
		return 1;
	}
	fseek(ptr1, 0, SEEK_END);
	filesize = ftell(ptr1);
	rewind(ptr1);
	buf = (char*) malloc(sizeof(char) * (filesize + 1));
	fread(buf, sizeof(char), filesize, ptr1);
 	buf[filesize] = '\0';
	fclose(ptr1);	
	printf("%s", buf);
		
	ptr2 = fopen("Statistics.txt", "r+");
	if (!ptr2)
	{
		printf("fopen2");
		return 1;
	}
	int Word_capacity = 0;
	for (int i = 0; i < filesize; ++i)
	{
		if (buf[i] == ' ' || buf[i] == '\n')
		{
			++Word_capacity;;
		}
	}
	printf("Word_capacity = %d\n", Word_capacity);
	Word* array = (Word*) malloc (sizeof(Word) * Word_capacity);
	int Word_size = 0;
	
}

int len(char* str)
{
        int size = 0;
        while (*str != '\0')
        {
                ++str;
                ++size;
        }
	return size;
}

int cmp_strings(char* W_str, char* buf, const int length)
{
	for (int i = 0; i < length; ++i)
	{
		if (W_str[i] != buf[i])
		{
			return -1;
		}
	}
	return 1;
}

int seek_word(Word* array, int Word_size, char* buf)
{
	int len_buf = len(buf);
        for (int i = 0; i < Word_size; ++i)
        {		
		if (len_buf != len(array[i].arr))
		{
			continue;
		}
		else if (cmp_strings(array[i].arr, buf, len_buf))
		{
			++array[i].cnt;
			printf("%s word was found\n", buf);
			return 1;
		}
        }
	printf("%s word was not found\n", buf);
	return -1;
}
