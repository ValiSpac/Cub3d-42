
#include "cub3d.h"

void	update_player_pos(t_player_data *data)
{
	if (data->move_pa_right)
		data->pa -= (float)PLAYER_ANGLE_SPEED / 100.0;
	if (data->move_pa_left)
		data->pa += (float)PLAYER_ANGLE_SPEED / 100.0;
	if (data->move_right)
	{
		data->pdx += (float)PLAYER_SPEED * sin(data->pa);
		data->pdy += (float)PLAYER_SPEED * cos(data->pa);
	}
	if (data->move_left)
	{
		data->pdx -= (float)PLAYER_SPEED * sin(data->pa);
		data->pdy -= (float)PLAYER_SPEED * cos(data->pa);
	}
	if (data->move_forward)
	{
		data->pdx += (float)PLAYER_SPEED * cos(data->pa);
		data->pdy -= (float)PLAYER_SPEED * sin(data->pa);
	}
	if (data->move_backward)
	{
		data->pdx -= (float)PLAYER_SPEED * cos(data->pa);
		data->pdy += (float)PLAYER_SPEED * sin(data->pa);
	}
}
