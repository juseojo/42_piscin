/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:58:07 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/28 16:22:47 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	init_order(int *order)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		order[i] = i + 1;
		i++;
	}
}

void	sort_order(int *order, char **argv)
{
	int	i;
	int	j;
	int	temp;
	int	small;

	temp = 0;
	i = 0;
	init_order(order);
	while (argv[order[i]])
	{
		j = i;
		small = j;
		while (argv[order[j]])
		{
			if (0 < ft_strcmp(argv[order[small]], argv[order[j]]))
			{
				temp = order[j];
				order[j] = order[small];
				order[small] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	order[100];

	(void)argc;
	i = 0;
	sort_order(order, argv);
	while (argv[order[i]])
	{
		j = 0;
		while (argv[order[i]][j])
		{
			write(1, &argv[order[i]][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
