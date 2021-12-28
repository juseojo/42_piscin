/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:36:21 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/28 17:48:20 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;
	long	num;

	num = (long)nb;
	i = 2;
	if (num < 2)
		return (0);
	while (i * i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}
