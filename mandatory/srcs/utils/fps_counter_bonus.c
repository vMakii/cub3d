/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:54:24 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/10 12:02:24 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_time(void)
{
	static int				first_call = 1;
	static struct timeval	start_time;
	struct timeval			tv;

	if (first_call)
	{
		gettimeofday(&start_time, NULL);
		first_call = 0;
		return (0.0);
	}
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec - start_time.tv_sec) + (tv.tv_usec - start_time.tv_usec)
		/ 1000000.0);
}

static void	update_frame_times(t_fps *fps_data, float frame_time)
{
	if (fps_data->frames_counted < 60)
	{
		fps_data->frame_times[fps_data->frame_index] = frame_time;
		fps_data->total_time += frame_time;
		fps_data->frames_counted++;
	}
	else
	{
		fps_data->total_time -= fps_data->frame_times[fps_data->frame_index];
		fps_data->frame_times[fps_data->frame_index] = frame_time;
		fps_data->total_time += frame_time;
	}
	fps_data->frame_index = (fps_data->frame_index + 1) % 60;
}

static void	calculate_fps(t_data *data, t_fps *fps_data)
{
	float	avg_frame_time;

	if (fps_data->frames_counted > 0)
	{
		avg_frame_time = fps_data->total_time / fps_data->frames_counted;
		data->time.fps = (int)(1.0f / avg_frame_time);
	}
	else
		data->time.fps = 60;
	if (data->time.fps < 1)
		data->time.fps = 1;
	if (data->time.fps > 1000)
		data->time.fps = 1000;
}

void	print_fps(t_data *data)
{
	int			current_fps;
	static int	old_fps = 0;
	static int	update_counter = 0;
	char		*fps;

	current_fps = data->time.fps;
	update_counter++;
	
	// Update displayed FPS every 30 frames for more responsive display
	if (update_counter >= 30 || old_fps == 0)
	{
		old_fps = current_fps;
		update_counter = 0;
	}
	
	fps = ft_itoa(old_fps);
	mlx_string_put(data->mlx.ptr, data->mlx.win, WIN_WIDTH - 60, 20,
		COLOR_WHITE, "FPS: ");
	mlx_string_put(data->mlx.ptr, data->mlx.win, WIN_WIDTH - 30, 20,
		COLOR_WHITE, fps);
	free(fps);
}

void	fps_counter(t_data *data)
{
	static t_fps	fps_data;
	static int		initialized = 0;

	g_frame_count++;
	if (!initialized)
	{
		memset(fps_data.frame_times, 0, sizeof(fps_data.frame_times));
		fps_data.frame_index = 0;
		fps_data.total_time = 0.0f;
		fps_data.frames_counted = 0;
		data->time.oldtime = get_time();
		initialized = 1;
		return;
	}
	if (g_frame_count >= 120)
		g_frame_count = 0;
	fps_data.current_time = get_time();
	data->time.frametime = fps_data.current_time - data->time.oldtime;
	data->time.time = fps_data.current_time;
	
	// Clamp frametime to reasonable values (1-1000 FPS range)
	if (data->time.frametime <= 0.001f || data->time.frametime > 1.0f)
		data->time.frametime = 0.016667f;
	
	data->time.oldtime = fps_data.current_time;
	update_frame_times(&fps_data, data->time.frametime);
	calculate_fps(data, &fps_data);
}

// Print FPS with more detailed info every 60 frames
// if (g_frame_count % 60 == 0)
// {
// 	printf("FPS: %d (avg frameTime: %.6f, current: %.6f, frames: %d)\n", 
// 		data->time.fps, fps_data.total_time / fps_data.frames_counted,
// 		data->time.frametime, fps_data.frames_counted);
// }