/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:51:47 by atambo            #+#    #+#             */
/*   Updated: 2024/11/16 14:51:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"

pthread_mutex_t mtx;

void *function(void *args)
{	
	t_phi *phi;
	t_phi *first;
	
	pthread_mutex_lock(&mtx);
	first = NULL;
	phi = (t_phi *)args;
	printf("---------------------------------------------------\n");
	printf("thread\t\t%ld\n", phi->thread);
	printf("id\t%d\n", phi->id);
	printf("death_t\t\t%ld\n", phi->death_t);
	printf("doa\t%d\n", phi->doa);
	printf("data\t\t%p\n", phi->data);
	printf("l_f\t\t%p\n", phi->l_f);
	if(!first)
		first = phi;
	if (phi->next)
	{		
		printf("r_f\t\t%p\n", phi->r_f);
		printf("next\t%d\n", phi->next->id);
		phi = phi->next;
	}
	printf("---------------------------------------------------\n");
	pthread_mutex_unlock(&mtx);
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_phi			*first;
		t_data			data;
		t_phi			*phi;

        pthread_mutex_init(&mtx, NULL);
		data_init(av, &data);
		phi = NULL;
		make_philos(&phi, &data);
		first = NULL;
        set_death_t(phi);

		// while(phi != first)
		// {
		// 	if (pthread_create(&(phi->thread), NULL, function, (phi)) != 0)
		// 	{
		// 		perror("Failed to create thread");
		// 		return 1;
		// 	}
		// 	usleep(100000);
		// 	if(!first)
		// 		first = phi;
		// 	if (phi->next)
		// 		phi = phi->next;
		// }

        // first = NULL;
		// while(phi != first)
		// {
		// 	pthread_join(phi->thread, NULL);
		// 	if(!first)
		// 		first = phi;
		// 	if (phi->next)
		// 		phi = phi->next;
		// }
        
		free_phi(&phi);
	}
	else
	{
		fprintf(stderr, "Usage: %s <number_of_threads>\n", av[0]);
		return 1;
	}
	return 0;
}

