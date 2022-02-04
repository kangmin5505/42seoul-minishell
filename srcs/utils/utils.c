/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:45:01 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/03 15:58:11 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_args(char	**args)
{
	char	**temp;

	temp = args;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}

char	*ft_strjoin2(char const *s1, char const *s2, const char *substr)
{
	char	*str;
	int		s1_len;
	int		substr_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	s1_len = ft_strlen(s1);
	substr_len = ft_strlen(substr);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + substr_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + substr_len + s2_len + 1);
	ft_strlcat(str, substr, s1_len + substr_len + s2_len + 1);
	ft_strlcat(str, s2, s1_len + substr_len + s2_len + 1);
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return ((int)(*ptr1 - *ptr2));
		ptr1++;
		ptr2++;
	}
	return ((int)(*ptr1 - *ptr2));
}

char	*ft_strndup(const char *s1, int n)
{
	int		s_len;
	char	*mem;
	int		idx;

	s_len = ft_strlen(s1);
	mem = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!mem)
		return (NULL);
	idx = 0;
	while (s1[idx] != '\0' && n)
	{
		mem[idx] = s1[idx];
		idx++;
		n--;
	}
	mem[idx] = '\0';
	return (mem);
}
