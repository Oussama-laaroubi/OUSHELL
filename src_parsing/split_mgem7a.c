/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mgem7a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:44:35 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/09 12:49:20 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int count_words(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
        
		while (*line && isspace(*line))
			line++;
		if (*line && !isspace(*line))
		{
			count++;
			while (*line && !isspace(*line))
            {
                                
				line++;
            }
		}
	}
	return (count);
}

// char    **split_mgem7a(char *line)
// {
    
// }