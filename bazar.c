				//result = call_ft_by_type(s[i +1], args, result);
					//if () si types % et args correspondent pas, ou pas le bon nombre d'args?
	//	return (-1);
		//ft_printf("CUSTOM : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);
	//printf("\nOFFICIAL : \n%c \n%s \n%p \n%d \n%i \n%u \n%x \n%X \n%%", c, s, p, d, i, u, hex, HEX);

	int	call_ft_by_type(char c, va_list args, int result)	
{
	//void	*p_temp;

	if (c == '%')
		result = putchar_fd('%', 1, result);
	else if (c == 'c')
		result = putchar_fd((char)va_arg(args, int), 1, result);
	else if (c == 's')
		result = putstr_fd(va_arg(args, char *), 1, result);
	/*else if (c == 'p') //faire un itoa?
	{
		p_temp = va_arg(args, void *);
		printf("Debug: %p\n", p_temp);
		result = putstr_fd((char *)&p_temp, 1, result);
	}*/
	else if (c == 'd' || c == 'i')
		result = putstr_fd(itoa_base(va_arg(args, int), 10), 1, result);
	//else if (c == 'u')
	//	result = putstr_fd(itoa_base((int)va_arg(args, unsigned int), 10), 1, result);
	//else if (c == 'x')
	//	result = putstr_fd(itoa_base(va_arg(args, int), 16), 1, result);
	//else if (c == 'X')
	//	result = putstr_fd(ft_toupper(itoa_base(va_arg(args, int), 16), 1, result));
	return (result);
}