/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:13:15 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/30 19:45:25 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_num(int src)
{
	long long		dig;
	long long		result;
	char			ch;
	long long		num;

	num = (long long)src;
	dig = 1;
	result = 0;
	if (src == 0)
		write(1, "0", 1);
	while (dig <= num)
		dig *= 10;
	dig /= 10;
	while (0 < dig)
	{
		ch = num / dig + '0';
		num = num % dig;
		dig /= 10;
		write(1, &ch, 1);
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		print_num(par[i].size);
		print_str(par[i].copy);
		i++;
	}
}
