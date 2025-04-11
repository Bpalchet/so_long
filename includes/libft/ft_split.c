/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:38:39 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/01 15:39:06 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_matrix(char **matrix, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free(matrix[k]);
		k++;
	}
	free(matrix);
}

static char	*ft_alloc_n_len(const char *s, char c, int i, int *len)
{
	char	*word;

	*len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		(*len)++;
		i++;
	}
	word = (char *)malloc((*len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + i - *len, *len + 1);
	word[*len] = '\0';
	return (word);
}

static char	**ft_split_words(const char *s, char c, int index[2], char **matrix)
{
	int	len;

	len = 0;
	while (s[index[0]] != '\0')
	{
		if (s[index[0]] != c)
		{
			matrix[index[1]] = ft_alloc_n_len(s, c, index[0], &len);
			if (!matrix[index[1]])
			{
				free_matrix(matrix, index[1]);
				return (NULL);
			}
			index[1]++;
			index[0] += len;
		}
		else
			index[0]++;
	}
	matrix[index[1]] = NULL;
	return (matrix);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	int		index[2];
	char	**matrix;

	count = ft_count(s, c);
	matrix = (char **)malloc((count + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	return (ft_split_words(s, c, index, matrix));
}

/*int main(void)
{
    const char *s = "ciao a tutti";
    char    c = 'a';
    char    **matrix = ft_split(s, c);
    int count = ft_count(s, c);
    int i = 0;
    if (!matrix)
    {
        fprintf(stderr, "Errore nell'allocazione della memoria.\n");
        return (1);
    }
    printf("Frase da splittare: '%s'\n", s);
    printf("La frase contiene le seguenti %d parole splittate:\n", count);
    while (i < count)
    {
        printf ("Frase splittata nr. %d: '%s'\n", i + 1, matrix[i]);
        free (matrix[i]);
        i++;
    }
    free (matrix);
    return (0);
}*/
