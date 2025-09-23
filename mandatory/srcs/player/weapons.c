/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:11:03 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/23 13:34:05 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_weapons(t_data *data)
{
	if (data->player.weapon.type == FIST)
	{
		data->player.weapon.damage = 10;
		data->player.weapon.range = 0.7f;
	}
	else if (data->player.weapon.type == SWORD)
	{
		data->player.weapon.damage = 25;
		data->player.weapon.range = 1.0f;
	}
	else if (data->player.weapon.type == MAGIC_SWORD)
	{
		data->player.weapon.damage = 40;
		data->player.weapon.range = 1.2f;
	}
}

// void	change_weapons(t_data *data)
// {
// 	if (data->player.weapon.type == FIST)
// 	{
// 		destroy_player(data);
// 		data->player.weapon.type = SWORD;
// 		load_player(data);
// 	}
// 	else if (data->player.weapon.type == SWORD)
// 	{
// 		destroy_player(data);
// 		data->player.weapon.type = MAGIC_SWORD;
// 		load_player(data);
// 	}
// 	else
// 	{
// 		destroy_player(data);
// 		data->player.weapon.type = FIST;
// 		load_player(data);
// 	}
// 	init_weapons(data);
// }

void change_weapons_up(t_data *data)
{
	if (data->player.weapon.type == FIST)
	{
		destroy_player(data);
		data->player.weapon.type = MAGIC_SWORD;
		load_player(data);
	}
	else if (data->player.weapon.type == SWORD)
	{
		destroy_player(data);
		data->player.weapon.type = FIST;
		load_player(data);
	}
	else
	{
		destroy_player(data);
		data->player.weapon.type = SWORD;
		load_player(data);
	}
	init_weapons(data);
}

void change_weapons_down(t_data *data)
{
	if (data->player.weapon.type == FIST)
	{
		destroy_player(data);
		data->player.weapon.type = SWORD;
		load_player(data);
	}
	else if (data->player.weapon.type == SWORD)
	{
		destroy_player(data);
		data->player.weapon.type = MAGIC_SWORD;
		load_player(data);
	}
	else
	{
		destroy_player(data);
		data->player.weapon.type = FIST;
		load_player(data);
	}
	init_weapons(data);
}
