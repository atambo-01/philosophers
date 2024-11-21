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

void	end_simulation()
{
	exit(1);
}

void	data_init(char **av, t_data *data)
{
	struct timeval tv;

	if (av[1] && av[2] && av[3] && av[4])
	{
		data->phi_n = ft_atoi(av[1]);
		data->ttd = ft_atoi(av[2]);
		data->tte = ft_atoi(av[3]);
		data->tts = ft_atoi(av[4]);
		if (data->phi_n <= 0 || data->ttd <= 0 ||
				data->tte <= 0 || data->tts <= 0)
			end_simulation();
	}
	else
		end_simulation();
	if (av[5])
	{	
		data->e_min = ft_atoi(av[5]);
		if (data->phi_n <= 0)
			end_simulation();
	}
	gettimeofday(&tv, NULL);
	data->start = tv;
}
void	make_philos(t_phi **phi, t_data *data)
{
    int i;

    i = 1;
    (*phi) = ft_malloc(sizeof(t_phi));
    (*phi)->id = i;
    (*phi)->doa = 1;
    (*phi)->data = data;
    (*phi)->next = NULL;
	(*phi)->l_f = NULL;
	(*phi)->r_f = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*phi)->r_f, NULL);
    t_phi *current = *phi;
	i++;
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
	if(data->phi_n > 1)
    {	
		current->next = *phi;
    	init_forks(*phi);
	}
}

void	init_forks(t_phi *phi)
{
	t_phi *prev;
	t_phi *first;

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
		if (phi->next && phi->r_f == phi->next->l_f)
			ft_printf("\tcorrect !!");
		ft_printf("\n");
		if (phi->next)
			phi = phi->next;
		// usleep(90000);
		i++;
	}
}
