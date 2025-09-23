/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 00:00:00 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_door_sprite(t_door *door)
{
	if (door->open_amount == 0.0f)
		door->sprite_index = 0;
	else if (door->open_amount < 1.0f)
		door->sprite_index = 1;
	else
		door->sprite_index = 2;
}

void	update_doors(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->doors.count)
	{
		if (data->doors.doors[i].is_open
			&& data->doors.doors[i].open_amount < 1.0f)
		{
			data->doors.doors[i].open_amount += data->doors.doors[i].open_speed;
			if (data->doors.doors[i].open_amount >= 1.0f)
				data->doors.doors[i].open_amount = 1.0f;
		}
		else if (!data->doors.doors[i].is_open
			&& data->doors.doors[i].open_amount > 0.0f)
		{
			data->doors.doors[i].open_amount -= data->doors.doors[i].open_speed;
			if (data->doors.doors[i].open_amount <= 0.0f)
				data->doors.doors[i].open_amount = 0.0f;
		}
		update_door_sprite(&data->doors.doors[i]);
		i++;
	}
}
