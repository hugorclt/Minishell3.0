/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:33:34 by hrecolet          #+#    #+#             */
/*   Updated: 2024/03/27 10:35:18 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		size;

	size = ft_strlen(s1);
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (size--)
		result[size] = s1[size];
	return (result);
}
