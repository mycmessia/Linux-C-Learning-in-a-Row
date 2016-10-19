#include <stdio.h>
#include <stddef.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
	int i = 0;
	int flag = 0;
	int indent = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		if (src[i] == ' '  || src[i] == '\t' ||
		    src[i] == '\n' || src[i] == '\r')
		{
			if(!flag)
			{
				dest[i] = ' ';
				flag = 1;
			}
			else
				indent++;
		}
		else
		{
			dest[i - indent] = src[i];
			flag = 0;
		}
	}

	for (; i - indent < n; i++)
		dest[i - indent] = '\0';

	return dest;
}

int main(void)
{
	char buf[200];
	char str[50] = "hello	world   		!";

	shrink_space(buf, str, 50);

	printf("%s\n", buf);

	return 0;
}
