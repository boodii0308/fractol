/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isitbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:33:37 by tebatsai          #+#    #+#             */
/*   Updated: 2019/05/15 20:52:34 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isitbase(char c)
{
	char	*t;
	char	*s;
	int		i;

	i = 0;
	t = "0123456789ABCDF";
	s = "0123456789abcdf";
	while (s[i] && t[i])
	{
		if (s[i] == c || t[i] == c)
			return (1);
		i++;
	}
	return (0);
}