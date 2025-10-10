/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:16:54 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/25 11:11:14 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	walking_animation_2(t_data *data, int walk_cycle)
{
	if (walk_cycle == 2)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (walk_cycle == 3)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left2, 0, WIN_HEIGHT
			- (data->texture.player_left2.height * UPSCALING));
	}
}

static void	walking_animation_1(t_data *data, double cycle_time)
{
	int	walk_cycle;

	walk_cycle = (int)(cycle_time / FRAME_DURATION);
	if (walk_cycle == 0)
	{
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (walk_cycle == 1)
	{
		upscale_img(data, &data->texture.player_right2, WIN_WIDTH
			- (data->texture.player_right2.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right2.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else
		walking_animation_2(data, walk_cycle);
}

// 60 frames for a full cycle
void	render_player_walking(t_data *data, double current_time)
{
	static double	walking_start_time = -1.0;
	double			elapsed_time;
	double			cycle_time;

	if (walking_start_time < 0)
		walking_start_time = current_time;
	elapsed_time = current_time - walking_start_time;
	// Utilisation de fmod pour un cycle continu
	cycle_time = fmod(elapsed_time, WALK_CYCLE_DURATION);
	walking_animation_1(data, cycle_time);
}
