#include "libftprintf.h"
#include <unistd.h>

int	putchar_fd(char c, int fd, int result)
{
	write(fd, &c, 1);
	result ++;
	return (result);
}

int	putstr_fd(char *s, int fd, int result)
{
	int	i;

	i = 0;
	while (s[i])
	{
		putchar_fd(s[i], fd, result);
		i ++;
	}
	return (result);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i ++;
	return (i);	
}