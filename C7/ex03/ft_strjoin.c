/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:09:59 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/30 09:39:19 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char*src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	strs_len(int size, char **strs)
{
	int	i;
	int length;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += str_len(strs[i]);
		i++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*result;

	length = 0;
	if (size <= 0)
		return (result = malloc(1));
	length = strs_len(size, strs);
	result = malloc(sizeof(char) * (length + ((size - 1) * str_len(sep))));
	if (result == 0)
		return (0);
	i = -1;
	while (++i < length + ((size - 1) * str_len(sep)))
		result[i] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
