/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:01:01 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/27 18:06:02 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H
#include "libft.h"

// main
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX_ARGS 100

// pwd
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#define PATH_MAX 4096

#include <stdbool.h>

void    ft_echo(char **args);

#endif