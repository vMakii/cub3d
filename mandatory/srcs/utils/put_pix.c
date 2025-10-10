/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:21 by gburtin           #+#    #+#             */
/*   Updated: 2025/09/23 11:14:11 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_color(t_image *texture, int x, int y)
{
	int	index;

	index = y * texture->size_line + x * (texture->bpp / 8);
	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (0);
	return (*(int *)(texture->image->data + index));
}

//put a pixel at (x, y) coordinates of the image
void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		index;

	index = y * img->size_line + x * (img->bpp / 8);
	if (x < 0 || y < 0)
		return ;
	pixel = img->data + index;
	*(int *)pixel = color;
}
