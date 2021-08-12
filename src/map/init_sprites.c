/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:54:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/12 16:55:42 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_wall(t_img *img, void *mlx)
{
	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_W, &img->wall.size.x, 
	&img->wall.size.y);
	img->wall.pixel = mlx_get_data_addr(img->wall.img, &img->wall.bpp, 
	&img->wall.line_size, &img->wall.endian);
}

void	init_empty(t_img *img, void *mlx)
{
	img->emp.img = mlx_xpm_file_to_image(mlx, PATH_E, &img->emp.size.x, 
	&img->emp.size.y);
	img->emp.pixel = mlx_get_data_addr(img->emp.img, &img->emp.bpp, 
	&img->emp.line_size, &img->emp.endian);
}

void	init_item(t_img *img, void *mlx)
{
	img->item.img = mlx_xpm_file_to_image(mlx, PATH_I, &img->item.size.x, 
	&img->item.size.y);
	img->item.pixel = mlx_get_data_addr(img->item.img, &img->item.bpp, 
	&img->item.line_size, &img->item.endian);

}

void	init_exit(t_img *img, void *mlx)
{
	img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EX, &img->exit.size.x, 
	&img->exit.size.y);
	img->exit.pixel = mlx_get_data_addr(img->exit.img, &img->exit.bpp, 
	&img->exit.line_size, &img->exit.endian);
}

void	init_player(t_img *img, void *mlx)
{
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PD, &img->player.down.size.x, 
	&img->player.down.size.y);
	img->player.down.pixel = mlx_get_data_addr(img->player.down.img, &img->player.down.bpp, 
	&img->player.down.line_size, &img->player.down.endian);

	img->player.top.img = mlx_xpm_file_to_image(mlx, PATH_PT, &img->player.top.size.x, 
	&img->player.top.size.y);
	img->player.top.pixel = mlx_get_data_addr(img->player.top.img, &img->player.top.bpp, 
	&img->player.top.line_size, &img->player.top.endian);

	img->player.left.img = mlx_xpm_file_to_image(mlx, PATH_PL, &img->player.left.size.x, 
	&img->player.left.size.y);
	img->player.left.pixel = mlx_get_data_addr(img->player.left.img, &img->player.left.bpp, 
	&img->player.left.line_size, &img->player.left.endian);

	img->player.right.img = mlx_xpm_file_to_image(mlx, PATH_PR, &img->player.right.size.x, 
	&img->player.right.size.y);
	img->player.right.pixel = mlx_get_data_addr(img->player.right.img, &img->player.right.bpp, 
	&img->player.right.line_size, &img->player.right.endian);
}
