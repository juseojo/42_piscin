/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:54:13 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/26 20:51:36 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	base_check(char	*base)
{
	int		i;
	int		j;
	char	overlap[100];

	i = -1;
	while (++i < 100)
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

int	is_base(char	ch, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	cut(char *str, char *base, int *i, int *j)
{
	int	count;

	*i = 0;
	*j = 0;
	count = 2;
	while (str[*i] && !is_base(str[*i], base))
		*i = *i + 1;
	while (str[*i + *j] && is_base(str[*i + *j], base))
	{
		if (str[*j] == '-')
			count++;
		*j = *j + 1;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}

long long	cul_result(char *str, char *base, int *i, int *j)
{
	long long	result;
	long long	dig;
	long long	count;
	long long	gisu;

	gisu = 0;
	dig = 1;
	result = 0;
	while (base[gisu])
		gisu++;
	while (*j > 0)
	{
		count = 0;
		while (base[count])
		{
			if (str[*i + *j - 1] == base[count])
				break ;
			count++;
		}
		result += count * dig;
		dig *= gisu;
		*j = *j - 1;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int			minus;
	int			i;
	int			j;
	long long	result;

	result = 0;
	if (base_check(base))
		return (0);
	minus = cut(str, base, &i, &j);
	result = cul_result(str, base, &i, &j);
	if (minus)
		result = -result;
	if ( result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int main()
{
	printf("%d\n", ft_atoi_base("10", "011"));
	printf("%d\n", ft_atoi_base("1234567890", "0123456789"));
	printf("%d\n", ft_atoi_base("10000000000000000", "01"));
	printf("%d\n", ft_atoi_base("5F5E100", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("104134211161", "0123456"));
	printf("%d\n", ft_atoi_base("-13344223434043", "01234"));
	printf("%d\n\n", ft_atoi_base("5EHNCKA", "0123456789ABCDEFGHIJKLMNOPQ"));

	printf("%d\n", ft_atoi_base("!@#$%^&*()", ")!@#$%^&*("));
	printf("%d\n", ft_atoi_base("IOOOOOOOOOOOOOOOO", "OI"));
	printf("%d\n", ft_atoi_base("<C<B\"\'\'", "\'\"\?>.<,QWERT ABC"));
	printf("%d\n", ft_atoi_base("Qa QR qQQQtQ", "aQqR Tt"));
	printf("%d\n", ft_atoi_base("-_{{}}||{}{}=}{", "=_|{}"));
	printf("%d\n", ft_atoi_base("D'ws;t4", "ZXCS DF12345;:'\"qwertyas@#$"));
	printf("%d\n", ft_atoi_base("^$O$M", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_= "));
	printf("%d\n\n", ft_atoi_base("!", "!@#$"));

	printf("T1: %d\n", ft_atoi_base("123456", "1234563"));
	printf("T2: %d\n", ft_atoi_base("1234", "12345-64"));
	printf("T3: %d\n", ft_atoi_base("1234", "12345678+"));
	printf("T4: %d\n", ft_atoi_base("", "1"));
	printf("T5: %d\n", ft_atoi_base("12345", ""));
	printf("T6: %d\n", ft_atoi_base("12345", "a12356a7"));
	printf("T7: %d\n", ft_atoi_base("     \t\v\f     +---------++-1235aaa776644", "a123567"));
	printf("T7: %d\n", ft_atoi_base("     \n\r\t     +---------++-1235aaa7766"  , "a123567"));
	printf("T8: %d\n", ft_atoi_base("            +----8----++-1235aaa7766", "a123567"));
	return 0;
}
