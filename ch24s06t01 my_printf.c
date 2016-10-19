#include <stdio.h>
#include <stdarg.h>

void my_printint(int n)
{
	char buf[20];
	int count = 0;

	do {

		buf[count++] = n % 10 +'0';
		n /= 10;

	} while(n);

	for (count--; count >= 0; count--)
		putchar(buf[count]);
}

void my_printf(const char *format, ...)
{
	va_list ap;
	char c;

	va_start(ap, format);
	while ((c = *format++))
	{
		switch(c) {
			case '%':{
				c = *format++;
				switch(c) {
					case 'c': {
						char ch = va_arg(ap, int);
						putchar(ch);
						break;
					}
					case 's': {
						char *p = va_arg(ap, char *);
						fputs(p, stdout);
						break;
					}
					case 'd': {
						int n = va_arg(ap, int);
						my_printint(n);
						break;
					}
					case 'f': {
						double n = va_arg(ap, double);
						my_printint(n);
						break;
					}
					default:
						putchar(c);
				}
				break;
			}
			default:
				putchar(c);
		}
	}
}


int main(void)
{
	my_printf("int%d, str%s, char%c, float%f",
		  24, "hello", 'c', 12.58);

	return 0;
}
