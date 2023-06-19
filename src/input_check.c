/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:14:16 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/17 13:44:12 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+' && s2[j] != '+')
		i++;
	else if (s2[j] == '+')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	norme_fixe1(char **split, int *s_inc)
{
	int	j;

	j = 1;
	while (split[j])
	{
		if (j != (*s_inc) && compare(split[(*s_inc)], split[j]) == 0)
			return (1);
		j++;
	}
	(*s_inc)++;
	return (0);
}

// check duplicates for both cases where we have a lot of args and when we have
// a string as params so we take care of the string 
// with split and the other one just
// looping through the args without loosing track
int	have_duplicates(char **av)
{
	int		i;
	int		j;
	int		s_inc;
	char	**split;

	i = 1;
	while (av[i])
	{
		s_inc = 0;
		split = ft_split(av[i], ' ');
		if (!split[s_inc])
			return (0);
		while (split[s_inc])
			if (norme_fixe1(split, &s_inc))
				return (1);
		j = 0;
		while (av[++j])
		{
			if (j != i && compare(av[i], av[j]) == 0)
				return (1);
		}
		free_split(split);
		i++;
	}
	return (0);
}

int	is_sign(char s)
{
	if (s == '=' || s == '-')
		return (1);
	return (0);
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}
