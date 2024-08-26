/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:45:40 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/25 22:44:37 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

        // INCLUDES //
        
#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MALLOC_ERROR -77

#define WORD 0
#define PIPE 1
#define INPUT 2  // cat < Makefile ======= cat Makefile
#define OUTPUT 3   // ls > out ==== ls than 7titiha f out
#define HEREDOC 4  // << delimiter
#define APPEND 5 


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

typedef struct s_tockens
{
    char    *word;
    int     type;
    struct s_tockens    *next;
}               t_tockens;

typedef struct  s_program
{
    t_tockens   *tocken_list;
    t_trash     *trash_list;
    t_env       *env_list;
}               t_program;





        // FUNCTIONS //
void        get_env(t_env **env_list, char **env);
t_trash	    *ft_add_trash(t_trash **head, void *addr);
void        free_trash(t_trash **head);
int         count_words(char *line);
int		    word_lenght(char *line);
char        **split_mgem7a(char *line);
void        tockenizing(char *line);
t_tockens	*ft_add_tocken(t_tockens **head, char *word, int type);
void ft_white_spaces(char *line);
int    valid_quotes(char *line);
void    ft_free_exit(char *line, bool exit);
int is_whitespace(int c);
int line_len(char *line);
char *add_space(char *line);


extern t_program g_data;
#endif