/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_mgem7a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:44:35 by olaaroub          #+#    #+#             */
/*   Updated: 2024/08/09 16:47:52 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static	char	*escape_quotes(char *line)
{
	int quotes = 0;
	
	if(*line == 34)
	{
		while(*line && quotes != 2)
		{
			if(*line == 34)
				quotes++;
			line++;
		}
	}
	else if(*line == 39)
	{
		while(*line && quotes != 2)
		{
			if(*line == 39)
				quotes++;
			line++;
		}
	}
	return line;
}

// static	int		word_lenght(char *line)
// {
// 	int quotes = 0;
// 	int i;
	
// 	while(line[i])
// 	{
// 		if(line[i] == 34)
// 		{
// 			while(line[i] && quotes != 2)
// 			{
// 				if(line[i] == 34)
// 					quotes++;
// 				line++;
// 			}
// 		}
// 		else if(line[i] == 39)
// 		{
// 			while(line[i] && quotes != 2)
// 			{
// 				if(line[i] == 39)
// 					quotes++;
// 				line++;
// 			}
// 		}
// 	}
// 	return line;
// }

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
                if(*line == 34 || *line == 39)
					line = escape_quotes(line);
				else
					line++;
            }
		}
	}
	return (count);
}

// static char	**fill_strings(char *line, char **result, int count)
// {
// 	int	k;
// 	int	l;

// 	k = -1;
// 	while (++k < count && *line)
// 	{
// 		while (isspace(*line) && *line)
// 			line++;
// 		l = word_lenght(line);
// 		result[k] = (char *)malloc((l + 1) * sizeof(char));
// 		ft_add_trash(&g_data.trash_list, result[k]);
// 		if (!result[k])
// 			return (ft_free(result, k));
// 		ft_copy(line, result[k]);
// 		line += l;
// 	}
// 	result[k] = 0;
// 	return (result);
// }

// char    **split_mgem7a(char *line)
// {
// 	char **result;
// 	int count;

// 	count = count_words(line);
// 	result = (char **)malloc(sizeof(char *) * count + 1);
// 	ft_add_trash(&g_data.trash_list, result);
// 	if(!result)
// 		return(NULL);
// 	result = fill_strings(line, result, count);
	
    
// }