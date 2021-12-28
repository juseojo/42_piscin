/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:56:00 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/29 17:56:35 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*index;
	int	length;
	int	i;

	length = max - min;
	if (min >= max)
		return (0);
	index = malloc(sizeof(int) * length);
	if (index == 0)
		return (-1);
	i = 0;
	while (i < length)
	{
		index[i] = min;
		min++;
		i++;
	}
	*range = index;
	return (i);
}
