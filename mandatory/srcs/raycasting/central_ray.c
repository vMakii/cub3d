/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:09:35 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_central_ray(t_data *data, t_ray *ray, int x)
{
	if (x == WIN_WIDTH / 2)
	{
		data->player.central_ray_distance = ray->perp_wall_dist;
		data->player.central_ray_map_x = ray->map.x;
		data->player.central_ray_map_y = ray->map.y;
	}
}
