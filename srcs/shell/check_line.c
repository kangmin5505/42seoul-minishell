/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:10:59 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/28 10:48:02 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_line(char *line)
{
	int	single_quote;
	int	double_quotes;
	int	parenthesis;

	single_quote = 0;
	double_quotes = 0;
	parenthesis = 0;
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
		if (single_quote % 2 == 0 && double_quotes % 2 == 0)
		{
			if (*line == '(')
				parenthesis++;
			else if (*line == ')')
				parenthesis--;
			if (parenthesis == -1)
				return (FALSE);
		}
		line++;
	}
	if (single_quote % 2 == 0 && double_quotes % 2 == 0 && parenthesis == 0)
		return (TRUE);
	return (FALSE);
}
