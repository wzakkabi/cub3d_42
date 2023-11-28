/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:48 by mbousbaa          #+#    #+#             */
/*   Updated: 2023/11/17 19:49:18 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **fix_map(char **map)
{
	char	**p;
	int		i;
	int		tmp;

	i = ((tmp = 0) ,0);
	if(!map)
		return NULL;
	while (map[i])
	{
		if (ft_strnstr(map[i], "111", ft_strlen(map[i])) != NULL)
			break ;
		i++;
	}
	while (map[i + tmp])
		tmp++;
	p = (char **)malloc((sizeof(char *)) * (tmp + 1));
	tmp = ((i--), 0);
	while (map[++i])
		p[tmp++] = ft_substr(map[i],0 , ft_strlen(map[i]));
	p[tmp] = 0;
	tmp = 0;
	while (map[tmp])
		free(map[tmp++]);
	free(map);
	return (p);
	
}

int	strlen_map_big_width_and_height(char **p, char c)
{
	int	i;
	int	big_value;

	i = 0;
	big_value = 0;
	while (p && p[i])
	{
		if(ft_strlen(p[i]) >= (size_t)big_value)
			big_value = ft_strlen(p[i]);
		i++;	
	}
	if(c == 'h')
		return i;
	return (big_value);
}

void strlen_wight_pointer(t_map *map)
{
	int	i;
	i = -1;
	while(map->map_s[++i])
		map->width_map[i] = ft_strlen(map->map_s[i]);
}

void	info_player(t_plr *p, t_map *m)
{
	int x;
	int y;
	
	y = -1;
	while(m->map_s[++y])
	{
		x = -1;
		while(m->map_s[y][++x])
		{
			if(m->map_s[y][x] == 'N')
			{
				p->x = (x * m->size_wall_y_x);
				p->y = (y * m->size_wall_y_x);
			}
		}
	}
	p->direction = 0;
	p->move_up_down = 0;
	p->move_right_or_left= 0;
	p->radius = m->size_wall_y_x * 0.3;
	p->speedmv = 2; //pix
	p->retactionangle = M_PI / 2;
	p->retactionsSpeed = 2 * (M_PI / 180);
	p->fovue_angle = 60 * (M_PI / 180);
	p->num_arys = m->Xwindows_width;
}

bool	movestp_not_into_wall(t_map *map, double movestp , double M)
{
	char test;
	int x;
	int y;
	x = ((map->plr->x + cos(map->plr->retactionangle + M) * movestp) / map->size_wall_y_x);
	y = ((map->plr->y + sin(map->plr->retactionangle + M) * movestp) / map->size_wall_y_x);
	if(x < 0 || y < 0 || y > map->height_map || x > map->width_map[y])
		return false;
	test = map->map_s[y][x];
	if(test == '1')
		return false;
	if(test == '1')
		return false;
	return true;
}

// void update_key(void *tmp)
// {
// 	double movestp;
// 	t_map *map = (t_map *)tmp;
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_W) == true)
// 		map->plr->move_up_down = 1; 
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) == true)
// 		map->plr->move_up_down = -1;
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_D) == true)
// 		map->plr->move_up_down = ;
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_A) == true)
// 		map->plr->move_up_down = ;
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT) == true)
// 		map->plr->direction = 1;
// 	else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT) == true)
// 		map->plr->direction = -1;
// 	map->plr->retactionangle += map->plr->direction * map->plr->retactionsSpeed;
// 	movestp = map->plr->move_up_down * map->plr->speedmv;
// 	if(movestp_not_into_wall(map, movestp) == true)
// 	{
// 		map->plr->x += cos(map->plr->retactionangle) * movestp;
// 		map->plr->y += sin(map->plr->retactionangle) * movestp;
// 	}
// 	init_mlx(map);
// 	movestp = 0;
// 	map->plr->move_up_down = 0; 
// 	map->plr->direction = 0;
// }
void update_key(void *tmp)
{
    double movestp;
    t_map *map = (t_map *)tmp;

  	map->plr->move_up_down = 0; 
    map->plr->move_right_or_left = 0;
    map->plr->direction = 0;
    if (mlx_is_key_down(map->mlx, MLX_KEY_W) == true)
        map->plr->move_up_down = 1;
    else if (mlx_is_key_down(map->mlx, MLX_KEY_S) == true)
        map->plr->move_up_down = -1;
    if (mlx_is_key_down(map->mlx, MLX_KEY_D) == true)
        map->plr->move_right_or_left = 1; // Move right
    else if (mlx_is_key_down(map->mlx, MLX_KEY_A) == true)
        map->plr->move_right_or_left = -1; // Move left
    if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT) == true)
        map->plr->direction = -1;
    else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT) == true)
        map->plr->direction = 1;
    map->plr->retactionangle += map->plr->direction * map->plr->retactionsSpeed;
    movestp = map->plr->move_up_down * map->plr->speedmv;
    if (movestp_not_into_wall(map, movestp, 0) == true)
    {
        map->plr->x += cos(map->plr->retactionangle) * movestp;
        map->plr->y += sin(map->plr->retactionangle) * movestp;
		movestp = 0;
    }
    movestp  = map->plr->move_right_or_left * map->plr->speedmv;
    if (movestp_not_into_wall(map, movestp, M_PI_2) == true)
    {
        map->plr->x += cos(map->plr->retactionangle + M_PI_2) * movestp;
        map->plr->y += sin(map->plr->retactionangle + M_PI_2) * movestp;
	}
    init_mlx(map);
}


void start_cub3d(t_map *map)
{
	int wight_big_value;
	map->Xwindows_width = 1150;
	map->Ywindows_height = 600;
	map->size_wall_y_x = 80;
	map->plr = malloc(sizeof(t_plr));
	if(!map->plr)
		exit(99);
	info_player(map->plr, map);
	wight_big_value = strlen_map_big_width_and_height(map->map_s, 'w');
	map->height_map = strlen_map_big_width_and_height(map->map_s, 'h');
	map->width_map = malloc(map->height_map * sizeof(int));
	strlen_wight_pointer(map);
	printf("w = %d, h = %d\n", wight_big_value, map->height_map);
	map->wall3d = malloc(sizeof(t_wall3d));
	map->wall3d->rays_angle = (double *)malloc(sizeof(double) * map->plr->num_arys);
	map->wall3d->small_distance = (double *)malloc(sizeof(double) * map->plr->num_arys);
	map->mlx = mlx_init(map->Xwindows_width, map->Ywindows_height,"cub3d", true);
	map->img = mlx_new_image(map->mlx, map->Xwindows_width, map->Ywindows_height);
	if(!map->img || mlx_image_to_window(map->mlx, map->img, 0, 0) < 0)
		error_mlx();
	init_mlx(map);
	mlx_loop_hook(map->mlx, update_key, map);
	mlx_loop(map->mlx);
}

void find_tab_change_it_to_sp(char **map)
{
	char *swap;
	int	x;
	int tmp;
	int y;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if(map[y][x] == '\t')
			{
				swap = malloc(ft_strlen(map[y]) + 4 + 1);
				x = -1;
				tmp = 0;
				while(map[y][++x] != '\t')
					swap[x] = map[y][x];
				while(x + tmp < x + 4)
					swap[x + tmp++] = ' ';
				tmp--;
				while(map[y][++x])
					swap[x + tmp] = map[y][x];
				swap[x + tmp] = 0;
				free(map[y]);
				map[y] = swap;
				x = -1;
			}
		}
	}
}

int main(int ac, char **av)
{
	t_map	*map;
	// int		i;
	
	if (ac < 2)
		return (printf("Error\n"));
	// if (ft_strncmp(av[1], ".cub", 4) != 0)
	// 	return (printf("Error\n"));
	map = read_map(av[1]);
	if (map == NULL)
		return (printf("Error\n"));
	// i = 0;
	// while(map->map_s[i])
	// {
	// 	printf("%s\n", map->map_s[i]);
	// 	i++;
	// }
	if (process_type_ids(map) != 6)
		return (1);
	
	if (process_map(map) != 1)
		return (1);
	map->map_s = fix_map(map->map_s);
	find_tab_change_it_to_sp(map->map_s);
	// i = 0;
	// while(map->map_s[i])
	// {
	// 	printf("%s\n", map->map_s[i]);
	// 	i++;
	// }
	// while(1);
	start_cub3d(map);
	// mlx_terminate(mlx);
	// Create and display the image.
	// printf("#################\n");
	// printf("NO=%d\n", map->map_fd);
	// printf("SO=%s\n", map->SO);
	// printf("WE=%s\n", map->WE);
	// printf("EA=%s\n", map->EA);
	// printf("F=%s\n", map->F);
	// printf("C=%s\n", map->C);
	// printf("\n#################END\n");
	return (0);
}