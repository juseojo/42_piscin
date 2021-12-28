/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:40:18 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/28 17:55:48 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_suso(long num)
{
	long	i;

	i = 2;
	while (i * i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long	i;
	long	num;

	num = (long)nb;
	if (num < 2)
		return (2);
	while (i * i < num)
	{
		i = 0;
		if (is_suso(num))
			return ((int)num);
		num++;
	}
	return ((int)num);
}
