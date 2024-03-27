/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:44:43 by hrecolet          #+#    #+#             */
/*   Updated: 2024/03/27 10:45:44 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	size;

	if (len == 0)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (len > size)
		len = size;
	if (size <= start)
		len = 0;
	ret = malloc(sizeof(char) * len + 1);
	if (!s || !ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
