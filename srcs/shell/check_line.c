/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:10:59 by kangkim           #+#    #+#             */
/*   Updated: 2022/02/04 12:30:05 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell.h"

int	check_line(char *line)
{
	int	single_quote;
	int	double_quotes;

	single_quote = 0;
	double_quotes = 0;
	while (*line != '\0')
	{
		if (double_quotes % 2 == 0)
		{
			if (*line == '\'')
				single_quote++;
		}
		if (single_quote % 2 == 0)
		{
			if (*line == '\"')
				double_quotes++;
		}
		line++;
	}
	if (single_quote % 2 == 0 && double_quotes % 2 == 0)
		return (TRUE);
	return (FALSE);
}
