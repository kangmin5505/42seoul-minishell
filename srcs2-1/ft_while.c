/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:10:00 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/05 20:57:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
t_clist *ft_merge_list(t_clist *s)
{
    t_clist *t[2];
    char    *data[2];
    int     order;
    data[0] = 0;
    order = 0;
    t[0] = s;
    while (t[0])
    {
        t[1] = t[0];
        if (t[0]->on)
        {
            data[1] = data[0];
            if (!data[0])
            {
                data[0] = ft_strjoin(t[0]->data, t[0]->next->data);
                order = t[0]->order;
                if (t[0]->data)
                    free(t[0]->data);
            }
            else
                data[0] = ft_strjoin(data[0], t[0]->next->data);
            if (t[0]->next->data)
                free(t[0]->next->data);
            if (data[1])
                free(data[1]);
        }
        else
            break ;
        t[0] = t[0]->next;
        free(t[1]);
    }
    t[1] = t[0];
    if (t[0] == s)
        return (s);
    t[0] = ft_initclist(data[0], 0, 0, 0);
    t[0]->order = order;
    if (t[1])
        t[0]->next = t[1]->next;
    else
        t[0]->next = 0;
    if (t[1])
        free(t[1]);
    return (t[0]);
}
void    ft_merge(t_interpret *in)
{
    t_interpret *root;
    t_clist     *a[3];
    int         i;
    root = in;
    while (root)
    {
        i = -1;
        while (++i < 5)
        {
            a[0] = 0;
            a[1] = root->list[i];
            while (a[1])
            {
                if (a[0])
                {
                    a[0]->next = ft_merge_list(a[1]);
                    a[0] = a[0]->next;
                }
                else
                {
                    a[0] = ft_merge_list(a[1]);
                    a[2] = a[0];
                }
                if (a[0])
                    a[1] = a[0]->next;
                else
                    a[1] = 0;
            }
            root->list[i] = a[2];
        }
        root = ft_iterator(root);
    }
}
char    *ft_substitute(char *str)
{
    char    *rs;
    int     code;
    char    *tmp;
    rs = 0;
    code = NOVAR;
    while (*str || code == VAR)
    {
        tmp = ft_val(&str, code);
        rs = ft_strjoin(rs, tmp);
        free(tmp);
        if (*str == '$')
        {
            code = VAR;
            str += 1;
        }
        else
            code = NOVAR;
    }
    return (rs);
}
char    *ft_val(char **t, int type)
{
    int     s;
    char    *rs;
    char    *n;
    char    *tmp;
    rs = 0;
    s = 0;
    if (type == VAR)
    {
        if (t[0][s] == 0)
            return (ft_strcpy("$", 0, 1, 0));
        while (t[0][s] && !(ft_spc(t[0] + s))
                && t[0][s] != '$' && t[0][s] != '?')
            ++s;
        if (t[0][s] == '?' && s == 0)
        {
            t[0] += s + 1;
            return (ft_itoa(get_exit_status()));
        }
        n = ft_strcpy(t[0], 0, s, 0);
        tmp = get_env(n);
        rs = ft_strcpy(tmp, 0, ft_strlen(tmp), 0);
        free(n);
    }
    else
    {
        s = ft_while(t[0], '$', OFF, NOTEND);
        rs = ft_strcpy(t[0], 0, s, 0);
    }
    t[0] += s;
    return (rs);
}
void    ft_valpret_all(t_interpret *in)
{
    t_interpret *root;
    int         i;
    t_clist     *t;
    root = in;
    while (root)
    {
        if (root->son == 0)
        {
            i = -1;
            while (++i < 5)
            {
                t = root->list[i];
                ft_valpret(t, i);
            }
        }
        root = ft_iterator(root);
    }
}
void    ft_valpret(t_clist *t, int flag)
{
    char    *data;
    char    *tmp;
    int     type;
    tmp = 0;
    while (t)
    {
        data = t->data;
        type = t->type;
        if (t->data)
        {
            if (type == SPACE)
                tmp = ft_substitute(data);
            else if (type == DQUOTE || type == QUOTE)
            {
                if (flag == DIN || type == QUOTE)
                    tmp = t->data;
                else
                    tmp = ft_substitute(data);
            }
        }
        t->data = tmp;
        t = t->next;
    }
}
void    ft_delimeters(t_interpret *in)
{
    t_clist     *root;
    t_interpret *rootx;
    rootx = in;
    while (rootx)
    {
        root = rootx->list[DI];
        while (root)
        {
            ft_deltotmp(root->data);
            root = root->next;
        }
        rootx = ft_iterator(rootx);
    }
}
void    ft_deltotmp(char *del)
{
    char    *tmp;
    int     fd;
    int     size;
    tmp = ft_strjoin("tmp/", del);
    fd = open(del, O_CREAT | O_WRONLY);
    free(tmp);
    readline(tmp);
    size = ft_strlen(tmp);
    while (ft_strcmp(tmp, del) != 0)
    {
        write(fd, tmp, size);
        write(fd, "\n", 1);
        readline(tmp);
    }
    close(fd);
}
