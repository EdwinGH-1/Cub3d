/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:17:39 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 12:37:00 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	ft_slen(const char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_count_str(char const *str, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
		{
			i++;
		}
		if (str[i] != '\0')
		{
			cnt++;
			while (str[i] != '\0' && str[i] != c)
			{
				i++;
			}
		}
	}
	return (cnt);
}

static char	*ft_copy_word(const char *s, char c, int *ind)
{
	char	*word;
	int		start;
	int		i;
	int		len;

	start = *ind;
	len = ft_slen(s, c, start);
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	*ind = start + len;
	return (word);
}

static void	*ft_free(char **split, int j)
{
	while (j > 0)
	{
		free(split[j - 1]);
		j--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = malloc((ft_count_str(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			split[j] = ft_copy_word(s, c, &i);
			if (split[j] == NULL)
			{
				return (ft_free(split, j));
			}
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

/*
#include <stdio.h>

void print_result(char **result)
{
    int i = 0;
    while (result[i] != NULL)
    {
        printf("Substring %d: %s\n", i, result[i]);
        free(result[i]); // Free each substring
        i++;
    }
    free(result); // Free the array of pointers
}

int main(void)
{
    char **result;

    // Test case 1: Standard case with multiple separators
    char str1[] = "abc;def;ghi";
    char sep1 = ';';
    result = ft_split(str1, sep1);
    printf("Test Case 1:\n");
	printf("Str: \"%s\", Sep: \"%c\"\n", str1, sep1);
    print_result(result);

    // Test case 2: String starts and ends with a separator
    char str2[] = ";;start;;;middle;;end;";
    char sep2 = ';';
    result = ft_split(str2, sep2);
    printf("\nTest Case 2:\n");
	printf("Str: \"%s\", Sep: \"%c\"\n", str2, sep2);
    print_result(result);

    // Test case 3: Consecutive separators
    char str3[] = "a;;b;;;;c";
    char sep3 = ';';
    result = ft_split(str3, sep3);
    printf("\nTest Case 3:\n");
	printf("Str: \"%s\", Sep: \"%c\"\n", str3, sep3);
    print_result(result);

    // Test case 4: No separators
    char str4[] = "nosplit";
    char sep4 = ';';
    result = ft_split(str4, sep4);
    printf("\nTest Case 4:\n");
	printf("Str: \"%s\", Sep: \"%c\"\n", str4, sep4);
    print_result(result);

    // Test case 5: Empty string
    char str5[] = "";
    char sep5 = ';';
    result = ft_split(str5, sep5);
    printf("\nTest Case 5:\n");
	printf("Str: \"%s\", Sep: \"%c\"\n", str5, sep5);
    print_result(result);

    return 0;
}
*/
