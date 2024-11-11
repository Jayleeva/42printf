int	ft_print(const char *s, ...)
{
	va_list args;
	int		count_sep;
	int		i;
	int		result;

	va_start(args, s);
	result = 0;
	count_sep = 0;
	i = 1;
	while (s[i])
	{
		if (s[i -1] == '%')
		{
			if (is_in_set(s[i]) == 1)
				count_sep ++;
			else
				return (-1);
		}
		i ++;
	}
	va_end(args);
	//ft_print_count(count_sep, s, args);
	return (result);
}
