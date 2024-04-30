/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:05 by cbaroi            #+#    #+#             */
/*   Updated: 2024/04/29 16:55:19 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_if_rectangular(t_game *game, char **argv)
{
	int		fd;
	int		i;
	int		len;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	i = -1;
	while (++i < game->map.height)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (len != game->map.width)
		{
			while (line != NULL)
				line = get_next_line(fd);
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	map_height(char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (i);
		}
		i++;
		free(line);
	}
}

int	map_width(char **argv)
{
	int		fd;
	int		length;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	length = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (length);
}

void	init_map(t_game *game, char **argv)
{
	game->collectables = 0;
	game->moves = 0;
	game->exit_pos.num = 0;
	game->player_pos.num = 0;
	game->map.height = map_height(argv);
	game->map.width = map_width(argv);
}

void	check_map(char **argv, t_game *game)
{
	int	(*check_functions [6]) (t_game *game, char **argv) = {
		&check_if_rectangular, &create_map,
		&copy_map, &ft_check_wall,
		&check_exit_player_collectables, &valid_path};
	int	i;

	init_map(game, argv);
	i = -1;
	while (++i < 6)
	{
		if (check_functions[i](game, argv) == 1)
		{
			if (i > 2)
				destroy_map(game);
			printf("Function %d failed\n", i);
			ft_error("Error\n", 1);
		}
	}
}