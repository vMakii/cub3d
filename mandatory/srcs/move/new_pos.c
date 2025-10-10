/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:38:07 by gburtin           #+#    #+#             */
/*   Updated: 2025/10/06 14:34:25 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_mov(t_coord_float *move, float unit)
{
	float	length;

	length = sqrtf(move->x * move->x + move->y * move->y);
	if (length > unit)
	{
		move->x = (move->x / length) * unit;
		move->y = (move->y / length) * unit;
	}
}

void	init_speed(t_data *data, float *unit)
{
	if (data->player.action == RUNNING)
		*unit = RUN_SPEED;
	else
		*unit = WALK_SPEED;
}

void	calculate_new_position(t_data *data, t_coord_float *move)
{
	float	unit;

	init_speed(data, &unit);
	if (data->keys.key_w)
	{
		move->x += unit * data->player.dir.x;
		move->y += unit * data->player.dir.y;
	}
	if (data->keys.key_s)
	{
		move->x -= unit * data->player.dir.x;
		move->y -= unit * data->player.dir.y;
	}
	if (data->keys.key_d)
	{
		move->x -= unit * data->player.dir.y;
		move->y += unit * data->player.dir.x;
	}
	if (data->keys.key_a)
	{
		move->x += unit * data->player.dir.y;
		move->y -= unit * data->player.dir.x;
	}
	normalize_mov(move, unit);
}
