/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:18 by atambo            #+#    #+#             */
/*   Updated: 2024/11/22 14:30:19 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"

void    add_usec(struct timeval *tv, long msec)
{

    msec *= 10000;
    tv->tv_usec += msec;
    // while(tv->tv_usec >= 1000000)
    // {
    //     tv->tv_usec -= 1000000;
    //     tv->tv_sec += 1;
    // }
}
void	print_philos(t_phi *phi)
{
	int i;
	t_phi	*first;

	i = 1;
	first = phi;
	while(phi != first || i == 1)
	{
		ft_printf("phi->id = %d", phi->id);
		ft_printf("\tl_f = %p\tr_f = %p", phi->l_f, phi->r_f);
		if (phi->next && phi->r_f == phi->next->l_f)
			ft_printf("\tcorrect !!");
		ft_printf("\n");
		if (phi->next)
			phi = phi->next;
		// usleep(90000);
		i++;
	}
}

//msec lss then 10 and dif between numbers is >= 6 <= 30