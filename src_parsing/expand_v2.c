/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:46:31 by olaaroub          #+#    #+#             */
/*   Updated: 2024/09/03 12:20:34 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    check_master_quotes(bool *double_flag, bool *single_flag, char c)
{
    if(c == '\"' && *double_flag == false && *single_flag == false)
        *double_flag = true;
    else if(c == '\"' && *double_flag == true && *single_flag == false)
        *double_flag = false;
    if(c == '\'' && *single_flag == false && *double_flag == false)
        *single_flag = true;
    else if(c == '\'' && *single_flag == true && *double_flag == false)
        *single_flag = false;
    
        
}

int check_env_name(char *buff)
{   
    t_env   *tmp;
    
    tmp = g_data.env_list;
    while(tmp)
    {
        if(!ft_strcmp(buff, tmp->name))
            return(1);
        tmp = tmp->next;
    }
    return -1;
    
}

int get_expanded(char *buff, int fd)
{
    t_env   *tmp;
    
    tmp = g_data.env_list;
    while(tmp)
    {
        if(!ft_strcmp(buff, tmp->name))
            return(free(buff), write(fd, tmp->value, ft_strlen(tmp->value)));
        tmp = tmp->next;
    }
    return 0;
}

void    expand(void)
{
    t_tockens   *tmp;
    char *buff;
    int i;
    int start;
    int end;
    int wrote;
    int fd;

    tmp = g_data.tocken_list;
    while(tmp)
    {
        i = 0;
        char rand[6];
        int fd2 = open("/dev/random", O_RDONLY);
        read(fd2, rand, 5);
        rand[5] = '\0';
        close(fd2);
        fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
        wrote = 0;
        while(tmp->word && tmp->word[i])
        {
            check_master_quotes(&g_data.double_flag, &g_data.single_flag, tmp->word[i]);
            if(tmp->word[i] == '$')
            {
                start = ++i;
                while(tmp->word[i] && ft_isalnum(tmp->word[i]))
                    i++;
                end = i ;
                buff = ft_substr(tmp->word, start, end - start);
                if(check_env_name(buff) == 1 && ((g_data.double_flag == false && g_data.single_flag == false)
                    || (g_data.double_flag == true )))
                    wrote += get_expanded(buff, fd);
                else if(check_env_name(buff) == 1)
                {
                    wrote += write(fd, "$", 1);
                    wrote += write(fd, buff, ft_strlen(buff));
                }
            }
            else
                wrote += write(fd, &tmp->word[i++], 1);
        }
        close(fd);
        fd = open("file.txt", O_RDONLY);
        tmp->word = get_next_line(fd);
        if(tmp->word)
            g_data.trash_list = ft_add_trash(&g_data.trash_list, tmp->word);
        close(fd);
        unlink(rand);
        tmp = tmp->next;
    }
}
