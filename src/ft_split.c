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

static int	ft_nbrword(char const *src, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (src[i])
	{
		if (src[i] == c)
			i++;
		else
		{
			word++;
			while (src[i] != c && src[i])
				i++;
		}
	}
	return (word);
}

static void	*ft_insert(char *dest, char const *src, int index, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		dest[i] = src[index - n];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_create_split(char **split, char const *src, char c, int line)
{
	int	i;
	int	i_line;
	int	len;

	i = 0;
	i_line = 0;
	while (i_line < line)
	{
		len = 0;
		while (src[i] == c && src[i])
			i++;
		while (src[i] != c && src[i])
		{
			len++;
			i++;
		}
		split[i_line] = (char *)malloc(1 + len * sizeof(char));
		if (!split[i_line])
			return ;
		ft_insert(split[i_line], src, i, len);
		i_line++;
	}
	split[i_line] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		line;

	if (!s)
		return (NULL);
	line = ft_nbrword(s, c);
	split = (char **)malloc((line + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_create_split(split, s, c, line);
	return (split);
}
