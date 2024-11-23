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

void	set_death_t(t_phi *phi)
{
    long int curr;

    curr = ft_get_msec();
    if (phi->death_t <= 0)
        return;
    if (curr > phi->death_t)
        end_sim();
    else if (curr == phi->death_t)
    {
        if (curr >= phi->death_t)
            end_sim();
    }
    phi->death_t = curr;
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

