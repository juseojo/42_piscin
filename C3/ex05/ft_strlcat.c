/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:16:52 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/26 12:58:51 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int	size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dst_len;

	dst_len = str_len(dest);
	src_len = str_len(src);
	if (dst_len > size)
		return (src_len + size);
	i = 0;
	while (src[i] && i < size - dst_len)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	if (!src[i] && size != 1)
		dest[dst_len + i] = 0;
	else if (dst_len == size)
		return (src_len + dst_len);
	else
		dest[dst_len + i - 1] = 0;
	return (src_len + dst_len);
}
