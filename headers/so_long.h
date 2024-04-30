#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE	1
# define SIZE			64

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_coord
{
	int	num;
	int	i;
	int	j;
}				t_coord;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*textures[10];
	t_map		map;
	t_coord		player_pos;
	t_coord		exit_pos;
	int			collectables;
	int			moves;
}				t_game;

// handle_key.c

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		handle_key(int key, t_game *game);

// update_image.c

void	update_image_init(t_game *game);
void	update_image(t_game *game, int key);

// game_init.c

void	image_error(t_game *game, char *message, int index);
void	init_images(t_game *game);
void	destroy_everything(t_game *game);
void	load_images(t_game *game);

// check_map03.c

int		find_char(t_game *game, char c);
void	flood_fill(t_game *game, int i, int j);
int		valid_path(t_game *game, char **argv);
void	find_player_and_exit_position(t_game *game);

// check_map02.c

int		check_exit_player_collectables(t_game *game, char **argv);
int		ft_check_wall(t_game *game, char **argv);
int		copy_map(t_game *game, char **argv);
int		create_map(t_game *game, char **argv);
void	destroy_map(t_game *game);

// check_map.c

void	check_map(char **argv, t_game *game);
int		map_height(char **argv);
int		map_width(char **argv);
void	init_map(t_game *game, char **argv);
int		check_if_rectangular(t_game *game, char **argv);

// check_args.c

void	ft_error(char *str, int status);
void	ft_file_check(char *file);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
void	check_args(int argc, char **argv);

// Get Next Line

char	*get_next_line(int fd);
int		sl(char *str);
char	*gnl_clean(char *to_free, char **to_null);
char	*gnl_line(char *str);
char	*f_strjoin(char *s1, char *s2);
char	*gnl_alloc(size_t num, size_t size);

#endif