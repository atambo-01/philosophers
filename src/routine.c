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

void   *is_eating(t_phi *phi)
{   
	if (!phi->data->run || !phi->r_f || !phi->l_f)
        return (NULL);
    if(phi->id % 2 == 0)
		ft_mutex_forks(phi, 1);

    else
		ft_mutex_forks(phi, 2);
	phi->death_t = ft_get_msec() + phi->data->ttd;
    ft_mutex_printf(phi, "is eating\n");
    usleep(phi->data->tte * 1000);
	ft_mutex_forks(phi, -1);
	phi->p_meals += 1;
    is_thinking(phi);
}

void    *is_thinking(t_phi *phi)
{
	if (!phi->data->run)
        return (NULL);
    ft_mutex_printf(phi, "is thinkig\n");
    is_sleeping(phi);
    
}

void    *is_sleeping(t_phi *phi)
{
	if (!phi->data->run)
        return (NULL);
    ft_mutex_printf(phi, "is sleeping\n");
    usleep(phi->data->tts * 1000);
    is_eating(phi);
}

void    *routine(void *args)
{	
	t_phi *phi;

	phi = (t_phi *)args;
    is_eating(phi);

}
