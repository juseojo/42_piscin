/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:17:14 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/30 10:57:49 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	 int	i;
	char	*dst;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(char) * i + 1);
	while (0 <= i)
	{
		dst[i] = src[i];
		i--;
	}
	return (dst);
}
