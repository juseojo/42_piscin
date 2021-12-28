/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:44:05 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/23 10:53:39 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int count, unsigned char	*hex)
{
	char	ch;

	write(1, "\\", 1);
	if (count == 1)
		write(1, "0", 1);
	while (count - 1 >= 0)
	{
		ch = hex[count - 1];
		write(1, &ch, 1);
		count--;
	}
}

void	tr_hex(int ten)
{
	int				count;
	unsigned char	hex_ch[300];
	int				mod;

	count = 0;
	while (1)
	{
		mod = ten % 16;
		if (mod < 10)
		{
			hex_ch[count] = '0' + mod;
		}
		else
		{
			hex_ch[count] = 97 + (mod - 10);
		}
		ten = ten / 16;
		count++;
		if (ten == 0)
			break ;
	}
	print_hex(count, hex_ch);
}

void	ft_putstr_non_printable(char	*str)
{
	int				i;
	char			ch;

	i = 0;
	while (str[i])
	{
		if (str[i] < (char)32 || (char)126 < str[i])
		{
			tr_hex(str[i]);
		}
		else
		{
			ch = str[i];
			write(1, &ch, 1);
		}
		i++;
	}
}
