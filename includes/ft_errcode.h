/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errcode.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:23:28 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/07 05:09:55 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRCODE_H

# define FT_ERRCODE_H

# define SUCCESS_A 1
# define RET_TO_PAR 0
# define PARSE_ERR_NODEL -1
# define PARSE_ERR_CPAR -2
# define PARSE_ERR_UNFIN_P -3
# define PARSE_ERR_UNFIN_Q -4
# define PARSE_ERR_EMPTYNEXT -5
# define PARSE_ERR_UNFIN_CPAR -6

# define NODEL "PARSE_ERROR -> NO DELIMETER\n"
# define CP "PARSE ERROR PARENTHESIS NOT OPENED\n"
# define UNFINP "PARSE ERROR PARENTHESIS NOT OPENED\n"
# define UNFINQ "PARSE ERROR QUOTE OR DEQUOTE NOT CLOSED\n"
# define UNFINCP "PARSE ERROR PARENTHESIS NOT CLOSED\n"
# define EMPTY "PARSE ERROR EMPTY\n"

#endif
