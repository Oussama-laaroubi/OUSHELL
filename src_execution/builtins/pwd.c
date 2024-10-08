/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:50:34 by ouboukou          #+#    #+#             */
/*   Updated: 2024/09/19 21:04:54 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void print_working_dir()
{
    char buff[PATH_MAX];
    char *str;
    
    str = getcwd(buff, sizeof(buff));
    if (NULL == str)
        perror("error getcwd");
    printf("%s\n", str);
}