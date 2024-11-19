#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	/*ft_printf("%c ", 'c');*/

	char			c = 'a';
	char			s[] = "hey";
	void			*p = &s;
	int				d = 2147483647;
	int				i = -2147483648;
	unsigned int	u = 4294967295;
	int				hex = 0x2a;
	int				HEX = 0x2B;

	ft_printf("CUSTOM c : \n> %c", c);
	ft_printf("CUSTOM s : \n> %s", s);
	ft_printf("CUSTOM p : \n> %p", p);
	ft_printf("CUSTOM d : \n> %d", d);
	ft_printf("CUSTOM i : \n> %i", i);
	ft_printf("CUSTOM u : \n> %u", u);
	ft_printf("CUSTOM hex : \n> %x", hex);
	ft_printf("CUSTOM HEX : \n> %X", HEX);

	ft_printf("CUSTOM : \n> %c \n> %s \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X \n> %%\n", NULL, s, p, d, i, u, hex, HEX);
	ft_printf("CUSTOM REVERSE : \n> %% \n> %X \n> %x \n> %u \n> %i \n> %d \n> %p \n> %s \n> %c\n", HEX, hex, u, i, d, p, s, c);

	printf("\nOFFICIAL : \n> %c \n> %s \n> %p \n> %d \n> %i \n> %u \n> %x \n> %X \n> %%\n", c, s, p, d, i, u, hex, HEX);
}
