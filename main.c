#include "libftprintf.h"

int	main(void)
{
	char		c = 'a';
	char		s[] = "hey";
	void		*p = &s;
	int		d = 2147483647;
	int		i = -2147483648;
	unsigned int	u = 4294967295;
	int		hex = 0x2a;
	int		HEX = 0x2B;

	//ft_printf("CUSTOM : \n> %a", c);
	//ft_printf("CUSTOM : \n> %s", s);
	//ft_printf("CUSTOM : \n> %p", p);
	//ft_printf("CUSTOM : \n> %d", d);
	//ft_printf("CUSTOM : \n> %i", i);
	//ft_printf("CUSTOM : \n> %u", u);
	//ft_printf("CUSTOM : \n> %x", hex);
	//ft_printf("CUSTOM : \n> %X", HEX);
	
	//ft_printf("CUSTOM short : \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X", p, d, i, u, hex, HEX);
	ft_printf("CUSTOM : \n> %c \n> %s \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X \n> %%\n", c, s, p, d, i, u, hex, HEX);
	ft_printf("CUSTOM REVERSE : \n> %% \n> %X \n> %x \n> %u \n> %i \n> %d \n> %p \n> %s \n> %c\n", HEX, hex, u, i, d, p, s, c);

	//printf("\nOFFICIAL : \n> %c \n> %s \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X \n> %%\n", c, s, p, d, i, u, hex, HEX);
}
