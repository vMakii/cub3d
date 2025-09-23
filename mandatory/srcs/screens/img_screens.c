/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_screens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:17:59 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_screens(t_data *data)
{
	if (data->texture.starting_screen_0.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.starting_screen_0.image);
	if (data->texture.starting_screen_1.image)
		mlx_destroy_image(data->mlx.ptr, data->texture.starting_screen_1.image);
}

void	load_screens(t_data *data)
{
	load_img(data, &data->texture.starting_screen_0,
		"./assets/xpm/screen/starting_screen_0.xpm");
	load_img(data, &data->texture.starting_screen_1,
		"./assets/xpm/screen/starting_screen_1.xpm");
}
