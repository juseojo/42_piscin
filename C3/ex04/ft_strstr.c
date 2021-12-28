/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:01:28 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/26 12:40:20 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len_index(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (--i);
}

char	*ft_strstr(char	*str, char	*to_find)
{
	int	length;
	int	j;
	int	k;
	int	same;

	j = -1;
	if (!to_find[0])
		return (str);
	else if (!str[0])
		return (0);
	length = len_index(to_find);
	while (str[++j + length])
	{
		same = 1;
		k = -1;
		while (++k < length + 1)
		{
			if (str[j + k] != to_find[k])
				same = 0;
		}
		if (same)
			return (&str[j]);
	}
	return (0);
}
