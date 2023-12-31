/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:22:01 by anguinau          #+#    #+#             */
/*   Updated: 2022/08/06 09:17:52 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char *ft_strndup(const char *s, int len, int start)
{
        size_t i;
        int j;
        int k;
        char *str;

        i = 0;
        j = 0;
        while (s[start + i] && j < len)
        {
                i++;
                j++;
        }
        str = malloc(i + 1);
        if (!str)
                return (NULL);
        k = 0;
        j = 0;
        while (i--)
                str[j++] = s[start + k++];
        str[j] = '\0';
        return (str);
}
