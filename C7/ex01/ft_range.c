/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:38:32 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/29 15:49:44 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*index;
	int	length;
	int	i;

	length = max - min;
	if (min >= max)
		return (0);
	index = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		index[i] = min;
		min++;
		i++;
	}
	return (index);
}
