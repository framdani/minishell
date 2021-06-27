#include "libft.h"

int		no_special_char(int c)
{
	if (!(ft_strchr("$\"\'|<> ", c)))
		return (1);
	return (0);
}
