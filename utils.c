/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:41 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/11/17 22:58:58 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_mlx(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	put_px(t_map *map, mlx_image_t *img, int x, int y, uint32_t color)
{
	int tmp = 0;
	int tx, ty;
	tx = x;
	ty = y;
	while(ty < y + map->Ywindows_height)
	{
		tx = x;
		while(tx < x + map->Xwindows_width)
		{
			mlx_put_pixel(img, tx, ty, color);
			tx++;
		}
		ty++;
	}
}

void	draw_map(t_map *map, mlx_image_t *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map->map_s[y])
	{
		x = -1;
		while(map->map_s[y][++x])
		{
			if(map->map_s[y][x] == '1')
				put_px(map, img, (x * map->Xwindows_width), y * map->Ywindows_height, 0xFF0000FF);
			else
				put_px(map, img, (x * map->Xwindows_width), y * map->Ywindows_height, 0x0);
		}
		y++;
	}
}

void	draw_line_direction(t_map *map)
{
	int x;
	int y;
	y = 0;
	while(y < 360)
	{
		x = 0;
		while(x < 40)
		{
			mlx_put_pixel(map->img, map->plr->x + map->plr->radius + x * cos(map->plr->retactionangle), map->plr->y + map->plr->radius + x * sin(map->plr->retactionangle), 0x007258);
			x++;
		}
		y++;
	}
}

void	draw_player(t_map *map, mlx_image_t *img)
{
	int i;
	int j;
	t_plr *ply;

	ply = map->plr;
	i = 0;
	while(i < 360)
	{
		j = 0;
		while(j < ply->radius)
		{
			mlx_put_pixel(img, ply->x + ply->radius + j * cos(i), ply->y + ply->radius + j * sin(i), 0x007258);
			j++;
		}
		i++;
	}
}


void	init_mlx(t_map *map)
{
	draw_map(map, map->img);
	draw_player(map, map->img);
	draw_line_direction(map);
}