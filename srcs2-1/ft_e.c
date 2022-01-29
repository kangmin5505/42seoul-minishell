/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:55:25 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/20 14:11:45 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ECHO 2
#define LS 3
#define FLAG 15
#define AND 1
#define OR 2

int	ft_e(t_interpret *in)
{
	t_interpret	*root;

	if (FLAG & root->flag)
	if (root->mom && (FLAG & root->mom->flag))
	root = in;
	while (root)
	{
		if (root->data)
			ft_start(root->data);
		if (root->son)
			ft_e(in->son);
		root = root->next;
	}
	if (ft_eerror(in))
		return (-1);
	return (0);
}

int	ft_start(t_interpret *in)
{
	int	cmd_type;

	type = ft_select(in);
	if (type == -1)
		return (-1);
}

int	ft_select(t_clist *c)
{
	char	*cmd;

	if (!c || !c->data || !*(c->data))
		return (-1);
	cmd = c->data;
	if (ft_equal, cmd, "echo\0")
		return (ECHO);
	else if (ft_equal(cmd, "ls\0"))
		return (LS);
	return (-1);
}
