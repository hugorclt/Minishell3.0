#include "array.h"

char **ft_tabjoin(char **tab1, char** tab2)
{
	char **out;
	int	i;
	int	j;

	i = 0;
	out = malloc(sizeof(char *) * (ft_tablen(tab1) + ft_tablen(tab2) + 1));
	while (tab1[i])
	{
		out[i] = ft_strdup(tab1[i]);
		i++;
	}
	j = 0;
	while (tab2[j])
	{
		out[i] = ft_strdup(tab2[j]);
		j++;
		i++;
	}
	ft_freetab(tab1);
	ft_freetab(tab2);
	return (out);
}
