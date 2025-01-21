/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npham <npham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:58:41 by vbui              #+#    #+#             */
/*   Updated: 2024/12/20 20:46:41 by npham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_arg_list	*a_t_l_err(char *message, t_arg_list *to_free)
{
	if (message != NULL)
		perror(message);
	if (to_free != NULL)
		free(to_free);
	return (NULL);
}

static t_arg_list	*last(t_arg_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_arg_list	*add_to_list(t_arg_list *list, char *arg_start, char *arg_end)
{
	t_arg_list	*element;
	t_arg_list	*last_ele;

	if (arg_start == NULL || arg_end == NULL)
		return (NULL);
	if (arg_end < arg_start)
		return (NULL);
	element = malloc(sizeof(t_arg_list));
	if (element == NULL)
		return (a_t_l_err("Malloc failed in adding element", NULL));
	element->next = NULL;
	element->arg_length = (arg_end - arg_start + 2);
	element->arg = malloc(element->arg_length * sizeof(char));
	if (element->arg == NULL)
		return (a_t_l_err("Malloc failed in adding argument", element));
	ft_strlcpy(element->arg, arg_start, element->arg_length);
	if (list == NULL)
		return (element);
	else
	{
		last_ele = last(list);
		last_ele->next = element;
		return (element);
	}
}
