/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:27 by atambo            #+#    #+#             */
/*   Updated: 2024/11/20 15:41:28 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"


void make_philos(t_phi **phi, t_data *data)
{
    int i;

    i = 1;
    (*phi) = ft_malloc(sizeof(t_phi));
    (*phi)->id = i;
    (*phi)->doa = 1;
    (*phi)->data = data;
    (*phi)->next = NULL;
    i++;
    t_phi *current = *phi;
    while (i <= data->phi_n)
    {
        current->next = ft_malloc(sizeof(t_phi));
        current = current->next;
        current->id = i;
        current->doa = 1;
        current->data = data;
        current->next = NULL;
        i++;
    }
    current->next = *phi;
    init_forks(*phi);
}


void	init_forks(t_phi *phi)
{
	t_phi *prev;
	t_phi *first;

	phi->l_f = NULL;
	phi->r_f = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phi->r_f, NULL);
	first = phi;
	prev = phi;
	phi = phi->next;
	while(phi != first)
	{
		phi->l_f = prev->r_f;
		phi->r_f = ft_malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(phi->r_f, NULL);
		prev = phi;
		phi = phi->next;
	}
	if ( phi != NULL)
		first->l_f = prev->r_f;

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
		if (phi->r_f == phi->next->l_f)
			ft_printf("\tcorrect !!");
		ft_printf("\n");
		phi = phi->next;
		usleep(90000);
		i++;
	}
}
