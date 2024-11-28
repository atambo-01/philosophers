/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:18 by atambo            #+#    #+#             */
/*   Updated: 2024/11/22 14:30:19 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"


void	print_data(t_data *data)
{
	printf("Data\n");
	printf("---------------------------------------------------\n");
	printf("run\t%d\n", data->run);
	printf("start\t%ld\n", data->start);
	printf("phi_n\t%d\n", data->phi_n);
	printf("ttd\t%d ms\n", data->ttd);
	printf("tte\t%d ms\n", data->tte);
	printf("tts\t%d ms\n", data->tts);
	printf("e_min\t%d\n", data->e_min);
	printf("---------------------------------------------------\n");
}
void	print_philos(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	printf("---------------------------------------------------\n");
	printf("Philos\n");
	while(phi != first)
	{
		printf("---------------------------------------------------\n");
		printf("thread\t%ld\n", phi->thread);
		printf("id\t%d\n", phi->id);
		printf("death_t\t%ld\n", phi->death_t);
		printf("meals\t%d\n", phi->p_meals);
		printf("data\t%p\n", phi->data);
		printf("l_f\t%p\n", phi->l_f);
        printf("r_f\t%p\n", phi->r_f);
		if(!first)
			first = phi;
		if (phi->next)
		{		
			printf("next\t%d\n", phi->next->id);
			phi = phi->next;
		}
	}
	printf("---------------------------------------------------\n");
}

long    ft_get_msec(void)
{
	long			msec;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	msec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (msec); 
}

static void	free_forks(t_phi **phi)
{
	t_phi	*current;
	t_phi	*first;

	if (!phi || !*phi)
		return;
	current = *phi;
	first = *phi;

	while (current)
	{
		current->l_f = NULL;                // Nullify left fork
		ft_free((void **)&(current->r_f)); // Free right fork

		if (current->next == first)        // Check if we've returned to the first node
			break;

		current = current->next;           // Move to the next node
	}
}

void	free_phi(t_phi **phi)
{
	t_phi	*current;
	t_phi	*next;
	t_phi	*first;

	if (!phi || !*phi)
		return;
	free_forks(phi);
	current = *phi;
	first = *phi;

	while (current)
	{
		next = current->next;     // Save the next node

		ft_free((void **)&current); // Free the current node

		if (next == first)        // Check if we've returned to the first node
			break;

		current = next;           // Move to the next node
	}
	*phi = NULL; // Nullify the list pointer
}



//msec lss then 10 and dif between numbers is >= 6 <= 30