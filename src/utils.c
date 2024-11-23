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

void	print_philos(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	while(phi != first)
	{
		printf("---------------------------------------------------\n");
		printf("thread\t%ld\n", phi->thread);
		printf("id\t%d\n", phi->id);
		printf("death_t\t%ld\n", phi->death_t);
		printf("doa\t%d\n", phi->doa);
		printf("data\t%p\n", phi->data);
		printf("l_f\t%p\n", phi->l_f);
		if(!first)
			first = phi;
		if (phi->next)
		{		
			printf("r_f\t%p\n", phi->r_f);
			printf("next\t%d\n", phi->next->id);
			phi = phi->next;
		}
	}
	printf("---------------------------------------------------\n");
}

long    ft_get_msec()
{
	long			msec;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	msec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (msec); 
}

// void	check_forks(t_phi *phi)
// {
// 	t_phi	*first;
// 	t_phi	*prev;

// 	first = NULL;
// 	prev = phi;
// 	while(phi != first)
// 	{
// 		pthread_join(phi->thread, NULL);
// 		if (!first)
// 			first = phi;
// 		else
// 		{
			
// 		}
// 		if (phi->next)
// 			phi = phi->next;
// 	}
// }

void	ft_free_phi(t_phi **phi)
{
	t_phi	*next;
	t_phi	*first;

	if (!phi || !*phi)
		return;
	first = *phi;
	while (*phi)
	{
		next = (*phi)->next;
		(*phi)->l_f == NULL;
		ft_free((void **)&((*phi)->r_f));
		if (*phi == first)
			break;
		*phi = next;
	}
}

void	rec_free_phi(t_phi **temp, t_phi **phi)
{
	// if (!(*temp))
	// 	return;
	if (*temp && (*temp)->next != *phi)
		rec_free_phi(&((*temp)->next), phi);
	(*temp)->data = NULL;
	ft_free((void **)temp);
}

//msec lss then 10 and dif between numbers is >= 6 <= 30