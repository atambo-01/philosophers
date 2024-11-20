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

void *function(void *args)
{
    t_phi *phi = (t_phi *)args; // Cast the argument to t_phi
    printf("---------------------------------------------------\n");
    printf("Hello from philosopher %d\n", phi->id);
//  printf("Start time: %ld.%06ld\n", phi->data->start.tv_sec, phi->data->start.tv_usec);
    return NULL;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int n_th = atoi(av[1]);
        if(n_th <= 0)
            exit(1);

        t_data  data;
        t_phi   *phi;

        phi = NULL;
        data.phi_n = n_th;
        gettimeofday(&data.start, NULL);
        make_philos(&phi, &data);
        print_philos(phi);

    //     // Create threads
    //     for (int i = 0; i < n_th; i++)
    //     {
    //         if (pthread_create(&(data.phi[i].t), NULL, function, &(data.phi[i])) != 0)
    //         {
    //             perror("Failed to create thread");
    //             return 1;
    //         }
    //     }

    //     // Join threads
    //     for (int i = 0; i < n_th; i++)
    //     {
    //         pthread_join(data.phi[i].t, NULL);
    //     }
    }
    else
    {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", av[0]);
        return 1;
    }
    return 0;
}

