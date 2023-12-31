/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:01:53 by jchene            #+#    #+#             */
/*   Updated: 2022/08/13 16:56:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int nb_cmds(int flag)
{
        static int ret = 0;
        t_parsing *tmp;

        if (flag)
                ret = -1;
        if (ret == -1)
        {
                tmp = (data())->p_start;
                ret = 0;
                while (tmp)
                {
                        if (tmp->flag == CMD)
                                ret++;
                        tmp = tmp->next;
                }
        }
        return (ret);
}

int pipe_at_end(t_parsing *cursor)
{
        t_parsing *tmp;

        tmp = cursor;
        if (tmp && tmp->flag == PIP)
                tmp = tmp->next;
        while (tmp && tmp->flag != PIP)
                tmp = tmp->next;
        if (tmp)
                return (1);
        return (0);
}

int fd_update(int *fd_ptr, int value)
{
        if (*fd_ptr >= 0)
                if (close(*fd_ptr) < 0)
                        return (iperror("minishell: close", 0));
        *fd_ptr = value;
        return (1);
}

int is_directory(char *string)
{
        DIR *dir;

        dir = opendir(string);
        if (dir)
        {
                closedir(dir);
                return (1);
        }
        return (0);
}

int next_word(void)
{
        if ((data())->p_index->flag == PIP)
                (data())->p_index = (data())->p_index->next;
        while ((data())->p_index && (data())->p_index->flag != PIP)
                (data())->p_index = (data())->p_index->next;
        return (1);
}
