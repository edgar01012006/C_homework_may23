#include <stdio.h>

int cmp_strings(char* buf, char* exit)
{
	int i = 0;
	for (; i < 4; ++i)
	{
		if (buf[i] != exit[i])
		{
			return 1;
		}
	}
	if (buf[i] == '\n' || buf[i] == '\0')
	{
		return 0;
	}
	return 1;
}

int main()
{
	FILE* ptr;
	ptr = fopen("input.txt", "w");
	char buf[20] = { '\0' };
	char exit[5] = "exit";
	while(cmp_strings(fgets(buf, 20, stdin), exit))
	{
		fputs(buf, ptr); 
	}
	fclose(ptr);
	return 1;	 	
}
