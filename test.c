#include <ft_string.h>

int	main(void)
{
	char h[] = "00000fg0d";
	int a = 0;

	(void)a;
	__builtin_printf("%s\n%zu\n", h, ft_strlen(h));
}
