/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:06:42 by arlamber          #+#    #+#             */
/*   Updated: 2023/04/12 11:20:02 by arlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_size
{
	int			x;
	int			y;
	int			height;
	int			width;
}				t_size;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			line;
	int			column;
	char		**map;
	void		*wall;
	void		*coin;
	void		*floor;
	void		*player;
	void		*shotgun;
	int			img_width;
	int			img_height;
	int			x;
	int			y;
	int			collect;
	int			mvt;
}				t_data;

//////////////////GNL
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s);
int		ft_strlen(const char *str);
char	*newline(char *stash, int byte);
char	*get_line(char *stash);

/////////////////parsing
char	**get_map(t_data *data, char **av);
int		ft_parsing1(char **str);
int		ft_square(char **str);
int		ft_wall(char **str);
int		ft_fullparse(int ret);
int		map_ber(char *str);
int		ft_parsing2(char **str);
int		ft_pec(int e, int p, int c);
int		space(char *str);
int		check_map(char **ret, char *str);
int		good_open(char **av);
int		verif_arg(int ac, char **av);
int		parse(char **str);
char	**f_fill(char **map, t_size size, int row, int col);
int		flood_fill(char **map, t_size *size, int x, int y);
int		pars_4(char **str, int e, int p, int c);
t_size	*player_pos2(char **str, t_size *size);
int		flopfill(char **str);
char	**copy_map(t_data *data);

////////////////libft
char	**ft_split(char const *s, char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(char *src);

//////////////////Display
void	display_map(t_data	*data);
void	aff_map(char **map, t_data *data);
char	*put_image(char c);
int		size(int i, char **av);
int		lenx(t_data *data);
int		key_hook(int keycode, t_data *data);
int		player_pos(t_data *data);
void	display_window(t_data *data, char **av);
void	aff_map2(t_data *data);
int		ft_texture(t_data *data);
void	ft_move_a(t_data *data);
void	ft_move_s(t_data *data);
void	ft_move_w(t_data *data);
void	ft_move_d(t_data *data);
int		max_collec(t_data *data);
void	aff_map3(t_data *data);

////////////////////////////free
int		ft_free_all(t_data *data);
void	ft_free_map(t_data *data);
void	ft_free_args(char **args);
char	**map_split(t_data *data);
void	ft_free(char **map);

#endif
