/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:45:56 by hrecolet          #+#    #+#             */
/*   Updated: 2024/03/27 10:48:09 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_substring(char const *s, unsigned int start, size_t end)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = start;
	i = 0;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!s || !ret)
		return (NULL);
	while (j < end && s[start + i])
	{
		ret[i] = s[start + i];
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
