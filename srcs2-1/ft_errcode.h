/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errcode.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:23:28 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 07:47:49 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRCODE_H

# define FT_ERRCODE_H

# define SUCCESS 1
# define RET_TO_PAR 0
# define PARSE_ERR_NODEL -1
# define PARSE_ERR_CPAR -2
# define PARSE_ERR_UNFIN_PAR -3
# define PARSE_ERR_UNFIN_Q -4
# define PARSE_ERR_EMPTYNEXT -5
# define PARSE_ERR_UNFIN_CPAR -6

# define NODEL "PARSE_ERROR -> NO DELIMETER\n"
# define CPAR "PARSE ERROR PARENTHESIS NOT OPENED\n"
# define UNFINPAR "PARSE ERROR PARENTHESIS NOT CLOSED\n"
# define UNFINQ "PARSE ERROR QUOTE OR DEQUOTE NOT CLOSED\n"
# define UNFINCPAR "PARSE ERROR PARENTHESIS NOT CLOSED\n"
# define EMPTY "PARSE ERROR EMPTY\n"

#endif
