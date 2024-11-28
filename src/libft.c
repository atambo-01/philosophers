/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:24:37 by atambo            #+#    #+#             */
/*   Updated: 2024/11/28 03:24:39 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr ++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr ++;
	}
	else if (*nptr == '+')
		nptr ++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + ((char)(*nptr) - '0');
		if ((res * sign > 2147483647) || (res * sign < -2147483648))
			return (0);
		nptr ++;
	}
	return ((int)(res * sign));
}

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{	
		free(*ptr);
		*ptr = NULL;
	}
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(1);
	return (ptr);
}
