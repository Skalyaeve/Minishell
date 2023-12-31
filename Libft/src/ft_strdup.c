/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:22:01 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/06 17:28:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char *ft_strdup(const char *s)
{
        size_t i;
        size_t j;
        size_t k;
        char *str;

        i = 0;
        if (!s)
                return (NULL);
        while (s[i])
                i++;
        str = malloc(i + 1);
        if (!str)
                return (NULL);
        j = -1;
        k = -1;
        while (i--)
                str[++j] = s[++k];
        str[++j] = s[++k];
        return (str);
}
