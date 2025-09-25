/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:16:54 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/25 11:54:56 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	running_animation_2(t_data *data, int running_cycle)
{
	if (running_cycle == 2)
	{
		// Position neutre (retour)
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (running_cycle == 3)
	{
		// Main gauche levée
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left2, 0, WIN_HEIGHT
			- (data->texture.player_left2.height * UPSCALING));
	}
}

// Animation équilibrée : alternance droite/gauche
static void	running_animation_1(t_data *data, double cycle_time)
{
	int	running_cycle;

	running_cycle = (int)(cycle_time / RUN_FRAME_DURATION) % RUN_FRAMES;
	
	if (running_cycle == 0)
	{
		// Position neutre
		upscale_img(data, &data->texture.player_right1, WIN_WIDTH
			- (data->texture.player_right1.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right1.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else if (running_cycle == 1)
	{
		// Main droite levée
		upscale_img(data, &data->texture.player_right2, WIN_WIDTH
			- (data->texture.player_right2.width * UPSCALING), WIN_HEIGHT
			- (data->texture.player_right2.height * UPSCALING));
		upscale_img(data, &data->texture.player_left1, 0, WIN_HEIGHT
			- (data->texture.player_left1.height * UPSCALING));
	}
	else
		running_animation_2(data, running_cycle);
}

static bool	check_player_moved(t_data *data)
{
	static t_coord_float	old_pos = {0, 0};
	t_coord_float			cur_pos;

	cur_pos.x = data->player.pos.x;
	cur_pos.y = data->player.pos.y;
	
	// Vérifier si le joueur a bougé
	if (fabs(cur_pos.x - old_pos.x) < 0.001f && fabs(cur_pos.y - old_pos.y) < 0.001f)
	{
		return (false);
	}
	
	// Mettre à jour la position précédente
	old_pos = cur_pos;
	return (true);
}

void	render_player_running(t_data *data, double current_time)
{
	static double	running_start_time = -1.0;
	static bool		was_moving = false;
	double			elapsed_time;
	double			cycle_time;
	bool			is_moving;

	is_moving = check_player_moved(data);
	
	// Si le joueur s'arrête, afficher idle
	if (!is_moving)
	{
		was_moving = false;
		running_start_time = -1.0;  // Réinitialiser le timer
		return (render_player_idle(data));
	}
	
	// Si le joueur vient de commencer à bouger, réinitialiser le timer
	if (!was_moving || running_start_time < 0)
		running_start_time = current_time;
	
	was_moving = true;
	elapsed_time = current_time - running_start_time;
	cycle_time = fmod(elapsed_time, RUN_CYCLE_DURATION);
	running_animation_1(data, cycle_time);
}
