/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:56:00 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/26 18:48:41 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	len_index(char	src[])
{
	long long	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	gisu_make(long long gisu[], long long	length, long long	quo, int	n)
{
	long long	rem;

	rem = quo % length;
	quo = quo / length;
	gisu[n] = rem;
	n++;
	if (quo == 0)
		return (n);
	n = gisu_make(gisu, length, quo, n);
	return (n);
}

int	base_check(char	*base)
{
	int		i;
	int		j;
	char	overlap[1000];

	i = -1;
	while (++i < 1000)
		overlap[i] = 0;
	i = 0;
	while (base[i])
	{
		j = 0;
		while (overlap[j])
		{
			if (base[i] == overlap[j])
				return (1);
			j++;
		}
		overlap[i] = base[i];
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	if (i == 0 || i == 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int	nbr, char	*base)
{
	long long	gisu[1000];
	char		ch;
	int			n;
	long long	lnbr;

	lnbr = (long long)nbr;
	if (base_check(base))
		return ;
	if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr = -lnbr;
	}
	n = gisu_make(gisu, len_index(base), lnbr, 0) - 1;
	while (n >= 0)
	{
		ch = base[gisu[n]];
		write(1, &ch, 1);
		n--;
	}
}
