/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:30:49 by vbui              #+#    #+#             */
/*   Updated: 2024/06/10 16:47:17 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_digit:
    Vérifie si le caractère est un chiffre.
    Retourne : 1 si le caractère est un chiffre, 0 sinon.
*/
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* is_sign:
    Vérifie si le caractère est un signe numérique, + ou -.
    Retourne : 1 si le caractère est un signe, 0 sinon.
*/
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}
