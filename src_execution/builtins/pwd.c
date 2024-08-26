/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouboukou <ouboukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:50:34 by ouboukou          #+#    #+#             */
/*   Updated: 2024/08/13 16:29:47 by ouboukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#define PATH_MAX 4096

void print_working_dir()
{
    char buff[PATH_MAX];
    char *str;
    
    str = getcwd(buff, sizeof(buff));
    if (NULL == str)
        perror("error getcwd");
    printf("%s\n", str);      
}
// i have to creat a function that takes the input using readline function and then excute the built in
int main()
{
    print_working_dir();
    return (0);
}