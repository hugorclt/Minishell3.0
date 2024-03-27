#include "string.h"

int ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\v' || c == '\t' || c == '\r'
			|| c == '\f' || c == '\r')
		return (1);
	return (0);
}
