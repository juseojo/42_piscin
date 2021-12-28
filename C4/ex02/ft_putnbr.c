/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:28:39 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/21 09:40:46 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	exc_check(int	num)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	else if (num == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	else
		return (1);
}

int	minus_check(int	num)
{
	if (num < 0)
		write(1, "-", 1);
	else
		return (0);
	return (1);
}

void	ft_putnbr(int	nb)
{
	 int	deg;
	 int	count;
	char	str;

	deg = 1;
	count = 0;
	if (exc_check(nb))
	{	
		if (minus_check(nb))
			nb = -nb;
		while ((nb / deg) >= 10)
		{
			count++;
			deg *= 10;
		}
		count++;
		while (0 < count--)
		{
			str = (nb / deg) + '0';
			write(1, &str, 1);
			nb -= ((nb / deg) * deg);
			deg /= 10;
		}
	}
}
