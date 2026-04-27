/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-gall <dle-gall@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 23:47:35 by dle-gall          #+#    #+#             */
/*   Updated: 2026/04/21 23:47:35 by dle-gall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	j;

	if (!str || str[0] == 0)
		return (0);
	i = 0;
	j = 0;
	if (str[0] != c)
		j = 1;
	while (str[i] != '\0')
	{
		if (i > 0 && str[i] != c && str[i - 1] == c)
			j++;
		i++;
	}
	return (j);
}

static char	*get_word(char const *str, int start, int end)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = end - start;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			end = i;
			while (s[end] != '\0' && s[end] != c)
				end++;
			tab[j] = get_word(s, i, end);
			if (!tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[words] = NULL;
	if (!fill_tab(tab, s, c))
		return (NULL);
	return (tab);
}
