
#include <fdf.h>

int    *ft_apply_view_choice_to_tab(t_fdf_env *env, int i, int j, int z)
{
    int     *bigtab;
    
    bigtab = (int *)malloc(sizeof(int) * 2);
    if (VIEW_MODE == 1)
    {
         bigtab[0] = X + ORI_X + ((j + 0.5 * z) * (STEP_X * (100+ZOOM)/100));
         bigtab[1] = Y + ORI_Y + ((i + 0.25 * z) * (STEP_Y + (100+ZOOM)/100));
    }
    if (VIEW_MODE == 2)
    {
         bigtab[0] = X + ORI_X + ((0.5 * j - 0.5 * i) * (STEP_X + (100+ZOOM)/100));
         bigtab[1] = Y + ORI_Y + ((-z + 0.25 * j + 0.25 * i) * (STEP_Y + (100+ZOOM)/100));
    }
    if (VIEW_MODE == 3)
    {
         bigtab[0] = X + ORI_X + ((0.5 * j - 0.5 * i) * (STEP_X + (100+ZOOM)/100));
         bigtab[1] = Y + ORI_Y + ((-z + 0.25 * j + 0.25 * i) * (STEP_Y + (100+ZOOM)/100));
    }
    return (bigtab);
}

void	ft_bigtab_filling(t_fdf_env *env, int **values)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < env->line_nb)
	{
		while (++j < SIZE)
			BIG_TAB[i][j] = ft_apply_view_choice_to_tab(env,i,j,values[i][j]);
		j = -1;
	}
}