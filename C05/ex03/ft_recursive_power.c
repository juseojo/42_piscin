/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:04:41 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/28 17:30:35 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (nb == 0 && power == 0)
		return (1);
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	if (power > 1)
	{
		result = result * ft_recursive_power(nb, power - 1);
	}
	return (result);
}
