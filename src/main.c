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

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_phi			*first;
		t_data			data;
		t_phi			*phi;

		data_init(av, &data);
		phi = NULL;
		make_philos(&phi, &data);
		first = NULL;
		print_data(&data);
		print_philos(phi);
		while(phi != first)
		{
			if (pthread_create(&(phi->thread), NULL, routine, (phi)) != 0)
			{
				perror("Failed to create thread");
				return 1;
			}
			usleep(10000);
			if(!first)
				first = phi;
			if (phi->next)
				phi = phi->next;
		}
		while(data.run)
		{
			check_philos(phi);
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
		free_phi(&phi);
	}
	else
	{
		fprintf(stderr, "Usage: %s <number_of_threads>\n", av[0]);
		return 1;
	}
	return 0;
}

