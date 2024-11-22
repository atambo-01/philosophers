/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:01:19 by atambo            #+#    #+#             */
/*   Updated: 2024/11/20 19:01:20 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"

void	set_dead_t(t_phi *phi)
{
	struct timeval  curr;

    gettimeofday(&tv, NULL);
    if (curr.tv_sec > phi->death_t->tv_sec)
        end_sim();
    else if (curr.tv_sec == phi->death_t.tv_sec)
    {
        if (curr.tv_usec >= phi->death_t.tv_usec)
            end_sim();
    }
    phi->death_t = tv;
    add_usec(phi->death_t, phi->data->ttd)
}
	
// 	phi->death_t = tv + phi->data->ttd
// }

// void	all_alive(t_phi *phi)
// {
// 	t_phi *first;
// 	while(phi->next != first)
// 	{
// 		if (phi->doa == 0)
// 			dead_philo();
// 		phi = phi->next;
// 	}
// }
// void	eating(t_phi *phi)
// {
// 	death_time(phi);
// }

// void	sleeping(t_phi *phi)
// {

// }
// void	thinking(t_phi *phi)
// {}

