/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:58:09 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/22 01:12:00 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lowwer_alp(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char	*str)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	lowwer_alp(str);
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			check++;
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			if (check == 0)
				str[i] -= 32;
			check++;
		}
		else
			check = 0;
		i++;
	}
	return (str);
}
