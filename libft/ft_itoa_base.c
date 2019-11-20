/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:17:40 by tebatsai          #+#    #+#             */
/*   Updated: 2019/08/04 15:44:02 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lenght(int n, int base)
{
	size_t			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char				*ft_itoa_base(int n, int base)
{
	char			*s;
	size_t			len;
	unsigned int	i;
	char			*radix;

	radix = "0123456789ABCDEF";
	len = lenght(n, base);
	i = n;
	if (n < 0)
	{
		i = -n;
		len++;
	}
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	s[--len] = radix[i % base];
	while (i /= base)
		s[--len] = radix[i % base];
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
