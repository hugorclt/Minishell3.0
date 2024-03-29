#ifndef ARRAY_H
# define ARRAY_H

#include <stdlib.h>
#include "string.h"

int ft_tablen(char **tab);
void	ft_freetab(char **tab);
char **ft_tabjoin(char **tab1, char** tab2);

#endif
