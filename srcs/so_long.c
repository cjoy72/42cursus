/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:48:55 by cbaroi            #+#    #+#             */
/*   Updated: 2024/04/30 13:21:59 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	check_map(argv, &game);
	game.mlx = mlx_init(game.mlx);
	if (game.mlx == NULL)
		ft_error("Error\nmlx_init failed\n", 1);
	game.window = mlx_new_window(game.mlx, game.map.width * SIZE,
			game.map.height * SIZE, "so_long");
	if (game.window == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		ft_error("Error\nmlx_new_window failed\n", 1);
	}
	init_images(&game);
	load_images(&game);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_loop(game.mlx);
	destroy_everything(&game);
}