#include <stdio.h>

/***********************************************************
	
	void 指针不能做算术操作
	size_t类型最小是0，如果再减就到了4294967295，二进制31个1
	
***********************************************************/

void *my_memmove(void *dest, const void *src, size_t n)
{	
	while (n > 0)
	{
		((char *)dest)[n] = ((char *)src)[n];
		n--;
	}
	((char *)dest)[n] = ((char *)src)[n];

	return (char *)dest;
}

int main(void)
{
	char buf[20] = "hello world!\n";
	my_memmove(buf + 1, buf, 14);
	printf(buf);
	return 0;
}
