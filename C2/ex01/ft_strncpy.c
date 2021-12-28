/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:35:02 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/23 10:07:31 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char	*dest, char	*src, unsigned int	n)
{
	unsigned int	i;
	unsigned int	end;

	i = 0;
	end = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == 0)
			end = 1;
		if (end)
			dest[i] = 0;
		i++;
	}
	return (dest);
}
