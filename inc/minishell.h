/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:45:40 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/08 13:30:14 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

        // INCLUDES //
        
#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>


        // STRUCTS //

        
typedef struct  s_trash
{
    void            *address;
    struct s_trash  *next;
}               t_trash;

typedef struct  s_env
{
    char            *name;
    char            *value;
    char            *line;
    struct s_env    *next;
    struct s_env    *prev;
}               t_env;


typedef struct  s_program
{
    t_trash     *trash_list;
    t_env       *env_list;
}               t_program;





        // FUNCTIONS //
void    get_env(t_env **env_list, char **env);
t_trash	*ft_add_trash(t_trash **head, void *addr);
void    free_trash(t_trash **head);


 extern t_program g_data;
#endif