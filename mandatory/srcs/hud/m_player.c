/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:38:27 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_on_map(t_data *data, t_rect *player_rect)
{
	t_coord_int	start;
	t_coord_int	end;

	start.x = data->texture.minimap.width / 2 * UPSCALING;
	start.y = data->texture.minimap.height / 2 * UPSCALING;
	end.x = start.x + data->player.dir.x * MINIMAP_SCALE;
	end.y = start.y + data->player.dir.y * MINIMAP_SCALE;
	draw_rect(&data->frame, *player_rect, COLOR_GREEN);
	draw_line(&data->frame, start, end, COLOR_GREEN);
}
