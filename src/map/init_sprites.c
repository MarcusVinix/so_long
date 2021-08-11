/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:54:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/11 15:55:21 by mavinici         ###   ########.fr       */
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
	img->player.img = mlx_xpm_file_to_image(mlx, PATH_P, &img->player.size.x, 
	&img->player.size.y);
	img->player.pixel = mlx_get_data_addr(img->player.img, &img->player.bpp, 
	&img->player.line_size, &img->player.endian);
}
