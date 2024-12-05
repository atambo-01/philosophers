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
	{
		ft_error("Error.Bad allocation - ft_malloc.", 1);
		exit(1);
	}
	return (ptr);
}

int	ft_error(char *msg, int e)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(e);
}

int	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
