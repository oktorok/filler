/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 07:08:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/06 02:03:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <mlx.h>
# include <math.h>

# define BRICK_LONG 2
# define BRICK_HEIGHT 1
# define MARGEN_X 300
# define MARGEN_Y 100
# define RESOLUTION_X 1920
# define RESOLUTION_Y 1080

# define PLAYER_ONE 'O'
# define PLAYER_TWO 'X'
# define WALLPAPER "images/hotline_filler.xpm"
# define PAUSE "images/pause.xpm"
# define BRICK_PLAYER_ONE_1517 "images/BRICK3A_15x17.xpm"
# define BRICK_PLAYER_TWO_1517 "images/BRICK3B_15x17.xpm"
# define BRICK_PLAYER_ONE_2440 "images/BRICK3A_24x40.xpm"
# define BRICK_PLAYER_TWO_2440 "images/BRICK3B_24x40.xpm"
# define BRICK_PLAYER_ONE_10099 "images/BRICK3A_100x99.xpm"
# define BRICK_PLAYER_TWO_10099 "images/BRICK3B_100x99.xpm"
# define COLOR_ALWAYS 0
# define COLOR_BRICK_PLAYER_ONE 0xc00999
# define COLOR_BRICK_PLAYER_TWO 0x068bff
# define COLOR_PLAYER_ONE_NFO 0xc00999
# define COLOR_PLAYER_TWO_NFO 0x068bff
# define PLAYER_ONE_WINS "images/player1wins.xpm"
# define PLAYER_TWO_WINS "images/player2wins.xpm"
# define DRAW "images/meh.xpm"

# define ESC 53
# define SPACE 49
# define ENDIAN 0
# define BITS 32
# define LINE_COLOR 0xFFFFFF

typedef struct	s_img
{
	void		*data;
	int			width;
	int			height;
}				t_img;

typedef struct	s_map
{
	int			dim[2];
	int			square[2];
	int			map_pos[2];
	t_img		*wallpaper;
	t_img		**bricks;
}				t_map;

typedef struct	s_piece
{
	int			pos[2];
	char		*shape;
	int			dim[2];
	char		player;
}				t_piece;

typedef struct	s_info
{
	void		**points_img;
	char		**players;
	int			pause;
	void		*progress;
	t_img		*img_pause;
	int			puntuation[2];
}				t_info;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_map		*map;
	t_piece		**piece;
	t_info		*info;
}				t_mlx;

void			ft_set_bricks(t_mlx *mlx);
t_img			*ft_set_xpm(t_mlx *mlx, char *file);
void			ft_initialice(t_mlx *mlx);
void			ft_print_map(t_mlx *mlx);
char			*ft_get_addrs(void *img, int sizeline);
void			ft_set_piece_pos(t_mlx *mlx);
int				ft_jump_piece(t_mlx *mlx);
void			ft_jump_map(int dim[2]);
void			ft_get_piece(t_mlx *mlx, int piece_dim[2]);
void			ft_place_brick(t_mlx *mlx, int row, int col, char player);
void			ft_place_piece(t_mlx *mlx, int pieza, char player);
void			ft_info(t_mlx *mlx);
void			ft_copy_piece(t_mlx *mlx);
void			ft_update_info(t_mlx *mlx, char player);
int				ft_keys(int code, void *mlx);
void			ft_progress(t_mlx *mlx, int width, int p1);
#endif
