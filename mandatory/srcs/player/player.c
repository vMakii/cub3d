/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:49:42 by mivogel           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_data *data)
{
	double	current_time;

	current_time = get_time();
	combat_player(data);
	if (data->player.action == WALKING)
		render_player_walking(data, current_time);
	else if (data->player.action == RUNNING)
		render_player_running(data, current_time);
	else if (data->player.action == ATTACKING)
		render_player_attacking(data, current_time);
	else if (data->player.action == CASTING)
		render_player_magick(data);
	else
		render_player_idle(data);
}
