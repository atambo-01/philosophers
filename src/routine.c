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
void    check_philos(t_phi *phi)
{
    
}

void   *is_eating(void *args)
{   
    long    time;
    t_phi   *phi;

    phi = (t_phi *)args;
    if (!phi->r_f || !phi->l_f)
        return (NULL);
    if(phi->id % 2 == 0)
    {
        pthread_mutex_lock(phi->r_f);
        if (phi->next)
            pthread_mutex_lock(phi->l_f);
    }
    else
    {
        if (phi->next)
            pthread_mutex_lock(phi->l_f);
        pthread_mutex_lock(phi->r_f);
    }
    time = ft_get_msec() - phi->data->start;
    printf("%ld\t%d is eating\n", time, phi->id);
    usleep(phi->data->tte);
    pthread_mutex_unlock(phi->l_f);
    pthread_mutex_unlock(phi->r_f);
    *is_thinking(phi);

}

void    *is_thinking(phi)
{

}

void    *is_sleeping(phi)
{}

// void    is_sleeping()
// {}

// void    is_thinknig()
// {}

// void    routine(t_phi *phi)
// {
//     while(1)
//     {
//         is_eating();
//         is_sleeping();
//         is_thinking();
//     }
// }

