/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:10:00 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/02/04 16:24:36 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_clist *ft_merge_list(t_clist *t)
{
    t_clist *root;
    t_clist *tmp;
    char    *rs;
    char    *tmpd;
    int     order;
    rs = 0;
    order = 0;
    root = t;
    while (root)
    {
        tmp = root;
        if (root->on)
        {
            tmpd = rs;
            if (!rs)
            {
                rs = ft_strjoin(root->data, root->next->data);
                order = root->order;
                if (root->data)
                    free(root->data);
            }
            else
                rs = ft_strjoin(rs, root->next->data);
            if (root->next->data)
                free(root->next->data);
            if (tmpd)
                free(tmpd);
        }
        else
            break ;
        root = root->next;
        free(tmp);
    }
    tmp = root;
    if (root == t)
        return (t);
    root = ft_initclist(rs, 0, 0, 0);
    root->order = order;
    if (tmp)
        root->next = tmp->next;
    else
        root->next = 0;
    if (tmp)
        free(tmp);
    return (root);
}
void    ft_merge(t_interpret *in)
{
    t_interpret *root;
    t_clist     *t;
    t_clist     *o;
    int         i;
    t_clist     *r;
    root = in;
    while (root)
    {
        i = -1;
        while (++i < 5)
        {
            o = 0;
            t = root->list[i];
            while (t)
            {
                if (o)
                {
                    o->next =  ft_merge_list(t);
                    o = o->next;
                }
                else
                {
                    o = ft_merge_list(t);
                    r = o;
                }
                if (o)
                    t = o->next;
                else
                    t = 0;
            }
            root->list[i] = r;
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
    while (*str)
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
char    *ft_getenv(char *str)
{
    static char *list[5] = {"a1", "a2", "a3", "a4", "a5"};
    static char *ans[5] = {"re", "tu", "rn", "pl", "es"};
    int i;
    i = -1;
    while (++i < 5)
        if (ft_strcmp(str, list[i]) == 0)
            return (ft_strcpy(ans[i], 0, 2, 0));
    return (0);
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
        while (t[0][s] && !(ft_spc(t[0] + s)) && t[0][s] != '$' && t[0][s] != '?')
                ++s;
        if (t[0][s] == '?' && s == 0)
        {
            t[0] += s;
            return (0);
            //return (ft_atoi(ft_get_exit_status(g_envs)));
        }
        n = ft_strcpy(t[0], 0, s, 0);
        //tmp = getenvs(g_envs, n);
        tmp = ft_getenv(n);
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
        i = -1;
        if (root->son == 0)
        {
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
    //tmp = ft_strjoin("tmp/", del);
    fd = open(del, O_CREAT | O_WRONLY);
    //free(tmp);
    //readline(tmp);
    size = ft_strlen(tmp);
    while(ft_strcmp(tmp, del) != 0)
    {
        write(fd, tmp, size);
        write(fd, "\n", 1);
        //readline(tmp);
    }
    close(fd);
}
