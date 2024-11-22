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
	pthread_mutex_lock(&mtx);
	t_phi *phi = (t_phi *)args; // Cast the argument to t_phi
	printf("---------------------------------------------------\n");
	printf("thread\t%ld\n", phi->thread);
    printf("id\t%d\n", phi->id);
    printf("death_t\t%lu.%lu\n", phi->death_t.tv_sec, phi->death_t.tv_usec);
    printf("doa\t%d\n", phi->doa);
    printf("data\t%p\n", phi->data);
    printf("l_f\t%p\n", phi->l_f);
    printf("r_f\t%p\n", phi->r_f);
    printf("next\t%d\n", phi->next->id);
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
        set_death_t(phi);
		// print_philos(phi);
		first = NULL;
        add_usec(&(phi->death_t), 60);
        printf("\n%lu\n", phi->death_t.tv_usec - phi->next->death_t.tv_usec);
		while(phi != first)
		{
			if (pthread_create(&(phi->thread), NULL, function, (phi)) != 0)
			{
				perror("Failed to create thread");
				return 1;
			}
			usleep(100000);
			if(!first)
				first = phi;
			if (phi->next)
				phi = phi->next;
		}

        first = NULL;
		while(phi != first)
		{
			pthread_join(phi->thread, NULL);
			if(!first)
				first = phi;
			if (phi->next)
				phi = phi->next;
		}
        ft_printf("\n%\n", phi->data->ttd);
	}
	else
	{
		fprintf(stderr, "Usage: %s <number_of_threads>\n", av[0]);
		return 1;
	}
	return 0;
}

