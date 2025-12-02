/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:31:48 by sakdil            #+#    #+#             */
/*   Updated: 2025/12/02 17:24:40 by segunes          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error\nMLX build failed.\n");
		free_error_exit(game);
	}
	game->win_x = WINDOW_WIDTH;
	game->win_y = WINDOW_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->win_x, game->win_y, "Cub3d");
	if (!game->win)
	{
		printf("Error\nFailed to create window.\n");
		free_error_exit(game);
	}
	game->img = mlx_new_image(game->mlx, game->win_x, game->win_y);
	if (!game->img)
	{
		printf("Error\nFailed to create image.\n");
		free_error_exit(game);
	}
	
}

static int	close_window(t_game *game)
{
	//freeleri buraya at
	printf("Exiting the game....");
	free_error_exit(game);
	return (0);	
}

static int	key_control(int keycode, t_game *game)
{
	if (keycode == 65307) 
	{
		close_window(game);
		return (0);
	}
	//W,A,S,D buraya gelecek
	return (0);
	
}
int raycasting(t_game *game)
{
	int x;
	int map_x;
	int map_y;
	double view_x;
	double ray_x;
	double ray_y;
	double hipo_x;
	
	x = 0;
	
	while(x < game->win_x)//ekranın en solundan en sağına gidiyoruz
	{
		view_x = 2 * x / game->win_x -1;//0 ile 2 arasında bir değer yapar -1 yapıncada -1 ile 1 arsında olucak
	//view değişkeni, o an döngüdeki x değerinin (yani ekranındaki piksel sütununun) bu çizgi üzerinde nereye denk geldiğini söyler.
		ray_x= game->vec_x + (game->plane_x * view_x);
		ray_y = game->vec_y + (game->plane_y * view_x);
		//Bu değerler görüş açısı

		x++;
	}
}



static int	game_loop(t_game *game)
{
	int	x;
	int	y;
	int	ceil_color;
	int	floor_color;

	y = 0;
	ceil_color = create_color(game->ceiling_r, game->ceiling_g, game->ceiling_b);
	floor_color = create_color(game->floor_r, game->floor_g, game->floor_b);
	while (y < game->win_y)
	{
		x = 0;
		while (x < game->win_x)
		{
			if (y < game->win_y / 2) 
				draw_pixel_to_image(x, y, ceil_color, game); //BU FONKSİYON YAZILACAK
			else 
				draw_pixel_to_image(x, y, floor_color, game);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	game_start(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_hook(game->win, 2, 1L << 0, key_control, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
