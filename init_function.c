/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:30:11 by akhouya           #+#    #+#             */
/*   Updated: 2022/05/16 18:33:50 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_func(t_solong *attribut)
{
	attribut->map = NULL;
	attribut->p_x = -1;
	attribut->error = 0;
	attribut->count_coin = 0;
	attribut->exit = 0;
	attribut->movement = 0;
}
